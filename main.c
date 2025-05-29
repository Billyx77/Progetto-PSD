#include <stdio.h>                      // Inclusione della libreria standard per I/O
#include <stdlib.h>                     // Inclusione della libreria standard per l'allocazione di memoria
#include <string.h>                     // Inclusione della libreria per le operazioni sulle stringhe
#include "attivita_list.h"              // Inclusione dell'header per le funzioni della lista delle attivita
#include "attivita.h"                   // Inclusione dell'header per la struttura Attivita

int main() {
    AttivitaList list = NuovaAttivitaList();
    Menu(list);
    return 0;
}