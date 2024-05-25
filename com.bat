@echo off
REM Устанавливаем переменную для пути к компилятору gcc
SET GCC_PATH=C:\gcc\bin\gcc.exe
REM Устанавливаем переменную для пути к исходному файлу
SET SOURCE_FILE=core\main.c
REM Устанавливаем переменную для выходного файла
SET OUTPUT_FILE=BIN\kernel.bin

REM Компилируем исходный файл в бинарный файл
%GCC_PATH% -nostdlib -o %OUTPUT_FILE% %SOURCE_FILE%

REM Ждем нажатия любой клавиши перед закрытием окна
pause
