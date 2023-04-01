@ECHO OFF
CHCP 65001
GCC -std=c99 -Wall -Wpedantic -Wextra -Wvla -g3 -c main.c
GCC -std=c99 -Wall -Wpedantic -Wextra -Wvla -g3 -c items.c
GCC items.o main.o -o app.exe

