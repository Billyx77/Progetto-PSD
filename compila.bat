@echo off
:: Compila i file sorgente
echo Compilazione in corso...
gcc -Wall -Wextra -std=c99 -c main.c -o main.o
gcc -Wall -Wextra -std=c99 -c attivita_list.c -o attivita_list.o

:: Link dei file oggetto
gcc -o programma main.o attivita_list.o

:: Verifica esito compilazione
if exist programma.exe (
    echo Compilazione completata con successo!
) else (
    echo Errore durante la compilazione.
)
pause
