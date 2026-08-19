#include <algorithm>
#include <array>
#include <cerrno>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#if defined(_WIN32)
#define FST_EXTENSION_API extern "C" __declspec(dllexport)
#define FST_EXTENSION_CALL __stdcall
#else
#define FST_EXTENSION_API extern "C"
#define FST_EXTENSION_CALL
#endif

namespace
{
constexpr char kVersion[] = "FST Sabre Armor Extension 1.0.0";
constexpr char kProtocolVersion[] = "v1";

void writeOutput(char* output, const int outputSize, const char* message) noexcept
{
    if (output == nullptr || outputSize <= 0)
    {
        return;
    }

    std::snprintf(output, static_cast<size_t>(outputSize), "%s", message);
    output[outputSize - 1] = '\0';
}

bool parseDamage(const char* input, double& damage) noexcept
{
    if (input == nullptr || *input == '\0')
    {
        return false;
    }

    errno = 0;
    char* end = nullptr;
    const double parsed = std::strtod(input, &end);
    if (end == input || *end != '\0' || errno == ERANGE || !std::isfinite(parsed) || parsed < 0.0 || parsed > 1.0)
    {
        return false;
    }

    damage = parsed;
    return true;
}

int toIntegrityPercent(const double damage) noexcept
{
    return static_cast<int>(std::lround((1.0 - damage) * 100.0));
}

const char* conditionFor(const std::array<double, 5>& damage) noexcept
{
    const double worstDamage = *std::max_element(damage.begin(), damage.end());
    const double hullDamage = damage[4];

    if (hullDamage >= 0.65 || worstDamage >= 0.80)
    {
        return "CRITICAL";
    }

    if (hullDamage >= 0.30 || worstDamage >= 0.45)
    {
        return "DEGRADED";
    }

    return "NOMINAL";
}

int assess(char* output, const int outputSize, const char** arguments, const int argumentCount) noexcept
{
    if (arguments == nullptr || argumentCount != 5)
    {
        writeOutput(output, outputSize, "ERROR|INVALID_ARGUMENT_COUNT");
        return 2;
    }

    std::array<double, 5> damage{};
    for (int index = 0; index < argumentCount; ++index)
    {
        if (!parseDamage(arguments[index], damage[static_cast<size_t>(index)]))
        {
            writeOutput(output, outputSize, "ERROR|INVALID_DAMAGE_VALUE");
            return 3;
        }
    }

    const char* condition = conditionFor(damage);
    const int alert = std::strcmp(condition, "CRITICAL") == 0 ? 1 : 0;
    std::snprintf(
        output,
        static_cast<size_t>(outputSize),
        "%s|%d|%d|%d|%d|%d|%s|%d",
        kProtocolVersion,
        toIntegrityPercent(damage[0]),
        toIntegrityPercent(damage[1]),
        toIntegrityPercent(damage[2]),
        toIntegrityPercent(damage[3]),
        toIntegrityPercent(damage[4]),
        condition,
        alert);
    output[outputSize - 1] = '\0';
    return 0;
}
}

FST_EXTENSION_API void FST_EXTENSION_CALL RVExtensionVersion(char* output, const int outputSize)
{
    writeOutput(output, outputSize, kVersion);
}

FST_EXTENSION_API void FST_EXTENSION_CALL RVExtension(char* output, const int outputSize, const char* function)
{
    try
    {
        if (function != nullptr && std::strcmp(function, "health") == 0)
        {
            writeOutput(output, outputSize, "v1|READY");
            return;
        }

        writeOutput(output, outputSize, "ERROR|UNKNOWN_FUNCTION");
    }
    catch (...)
    {
        writeOutput(output, outputSize, "ERROR|UNHANDLED_EXCEPTION");
    }
}

FST_EXTENSION_API int FST_EXTENSION_CALL RVExtensionArgs(
    char* output,
    const int outputSize,
    const char* function,
    const char** arguments,
    const int argumentCount)
{
    try
    {
        if (function != nullptr && std::strcmp(function, "assess-v1") == 0)
        {
            return assess(output, outputSize, arguments, argumentCount);
        }

        writeOutput(output, outputSize, "ERROR|UNKNOWN_FUNCTION");
        return 1;
    }
    catch (...)
    {
        writeOutput(output, outputSize, "ERROR|UNHANDLED_EXCEPTION");
        return 99;
    }
}