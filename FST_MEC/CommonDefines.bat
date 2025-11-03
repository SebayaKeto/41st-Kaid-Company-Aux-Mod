 @echo off
    set "source_file=P:\FST\FST_MEC\mec_base_defines.hpp"
    set "parent_folder=P:\FST\FST_MEC"

    echo Copying "%source_file%" to all subfolders under "%parent_folder%"...

    FOR /D %%d IN ("%parent_folder%\*") DO (
        IF EXIST "%%d" (
            COPY /Y "%source_file%" "%%d"
            echo Copied to "%%d"
        )
    )

    echo Copying complete.
    pause