@ECHO OFF
CHCP 65001
GCC -std=c99 -Wall -Wpedantic -Wextra -Wvla -c main.c
GCC -std=c99 -Wall -Wpedantic -Wextra -Wvla -c items.c
GCC items.o main.o -o app.exe
