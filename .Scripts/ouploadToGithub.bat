@echo off
IF [%1]==[] (
    echo Usage ./o.bat [Problem Number]
    exit /b 1
)
set /a res=%1/1000
set /a res=%res*1000
IF EXIST ".\%res%\%1%.cpp" (
    echo . > null
) ELSE (
    echo File missing create file...
    mkdir %res% > null
    copy .\cppPreset.cpp .\%res%\%1%.cpp > null
)

git add .\%res%\%1%.cpp
git commit -m "Added %1%.cpp"
git push origin master