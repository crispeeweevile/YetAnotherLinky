@echo off
if exist "build\main.exe" (del "build\main.exe")
gcc -Wall -I include/ -std=c11 src/*.c -o build\main.exe