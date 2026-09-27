"""Span-keeping reader for text mission.sqm (Arma config text).

Parses enough of the grammar for Stonewall: classes, scalar properties,
arrays and "a" \\n "b" string joins.  Every class node keeps byte offsets
into the source text, so edits can be spliced in without re-writing (and
possibly damaging) the rest of the file.
"""
import re

TOKEN = re.compile(r'"(?:[^"]|"")*"|[A-Za-z_][A-Za-z0-9_]*|[-+]?(?:\d+\.?\d*|\.\d+)(?:[eE][-+]?\d+)?|\\n|\+=|[{}\[\];=:,]|\S')


class SqmError(ValueError):
    pass


class Node:
    __slots__ = ("name", "base", "start", "body", "end", "stmt_end", "classes", "props", "spans")

    def __init__(self, name, base=None, start=0):
        self.name, self.base, self.start = name, base, start
        self.body = self.end = self.stmt_end = None
        self.classes, self.props, self.spans = [], {}, {}

    def cls(self, name):
        n = name.casefold()
        for c in self.classes:
            if c.name.casefold() == n:
                return c
        return None

    def prop(self, name, default=None):
        return self.props.get(name.casefold(), default)

    def path(self, *names):
        n = self
        for name in names:
            n = n.cls(name) if n else None
        return n


def _unquote(s):
    return s[1:-1].replace('""', '"')


def _num(s):
    try:
        return int(s)
    except ValueError:
        return float(s)


class Parser:
    def __init__(self, text):
        self.text = text
        self.toks = [(m.group(0), m.start()) for m in TOKEN.finditer(text)]
        self.i = 0

    def peek(self, k=0):
        j = self.i + k
        return self.toks[j][0] if j < len(self.toks) else None

    def take(self, want=None):
        if self.i >= len(self.toks):
            raise SqmError(f"unexpected end of file (wanted {want})")
        t, pos = self.toks[self.i]
        if want is not None and t != want:
            line = self.text.count("\n", 0, pos) + 1
            raise SqmError(f"line {line}: expected {want!r}, got {t!r}")
        self.i += 1
        return t, pos

    def parse(self):
        root = Node("", start=0)
        root.body = 0
        self._body(root, top=True)
        root.end = len(self.text)
        return root

    def _body(self, node, top=False):
        while True:
            t = self.peek()
            if t is None:
                if top:
                    return
                raise SqmError(f"class {node.name}: missing closing brace")
            if t == "}":
                if top:
                    raise SqmError("stray closing brace")
                _, pos = self.take("}")
                node.end = pos
                return
            if t == ";":
                self.take()
                continue
            if t == "class":
                _, start = self.take()
                name, _ = self.take()
                base = None
                if self.peek() == ":":
                    self.take()
                    base, _ = self.take()
                c = Node(name, base, start)
                if self.peek() == "{":
                    _, b = self.take("{")
                    c.body = b + 1
                    self._body(c)
                _, semi = self.take(";")
                c.stmt_end = semi + 1
                node.classes.append(c)
                continue
            name, start = self.take()
            if self.peek() == "[":
                self.take("[")
                self.take("]")
                op, _ = self.take()
                if op not in ("=", "+="):
                    raise SqmError(f"{name}[]: bad operator {op}")
                value = self._array()
            else:
                self.take("=")
                value = self._scalar()
            _, semi = self.take(";")
            node.props[name.casefold()] = value
            node.spans[name.casefold()] = (start, semi + 1)

    def _scalar(self):
        t, _ = self.take()
        if t.startswith('"'):
            parts = [_unquote(t)]
            while self.peek() == "\\n" and (self.peek(1) or "").startswith('"'):
                self.take()
                parts.append(_unquote(self.take()[0]))
            return "\n".join(parts)
        try:
            return _num(t)
        except ValueError:
            return t

    def _array(self):
        self.take("{")
        out = []
        while self.peek() != "}":
            if self.peek() == ",":
                self.take()
                continue
            out.append(self._array() if self.peek() == "{" else self._scalar())
        self.take("}")
        return out


def parse(text):
    return Parser(text).parse()


def iter_entities(entities_node, layer_path=()):
    """Yield (node, layer_path) for every entity below a class Entities, recursing into layers and groups."""
    if entities_node is None:
        return
    for item in entities_node.classes:
        dt = str(item.prop("dataType", ""))
        yield item, layer_path
        if dt in ("Layer", "Group"):
            sub = layer_path + ((str(item.prop("name", "")),) if dt == "Layer" else ())
            yield from iter_entities(item.cls("Entities"), sub)


def max_id(node):
    m = node.prop("id", -1)
    m = m if isinstance(m, int) else -1
    for c in node.classes:
        m = max(m, max_id(c))
    return m


def sqm_string(s):
    return '"' + str(s).replace('"', '""').replace("\n", '" \\n "') + '"'
