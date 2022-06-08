@echo off
IF [%1]==[] (
    echo Usage ./o.bat [Problem Number]
    exit /b 1
)
set /a res=%1/1000
set /a res=%res*1000
IF EXIST ".\%res%\%1%.png" (
    echo . > null
) ELSE (
    echo File missing create file...
    mkdir %res% > null
    copy .\Blank.png .\%res%\%1%.png > null
)

code .\%res%\%1%.png
exit