#ifndef ATTIVITA_LIST_H                                             // Inizio del blocco di inclusione
#define ATTIVITA_LIST_H                                             // Definizione della macro per evitare inclusioni multiple

#include <stdbool.h>                                                // Inclusione della libreria per il tipo bool
#include "attivita.h"                                               // Inclusione del file header di Attivita

// Dichiarazione di un tipo opaco per la lista delle attivita
typedef struct attivitaList* AttivitaList;

// Dichiarazione delle funzioni dell'ADT ReservationList

// Crea e restituisce una lista vuota di attvita
AttivitaList NuovaAttivitaList(void);

// Verifica se la lista delle attivita e vuota
bool EmptyAttivitaList(AttivitaList list);

// Aggiunge una attivita in cima alla lista
AttivitaList AggiungiAttivita(AttivitaList list, Attivita att);

// Permette di visualizzare le attivita
void VisualizzaAttivita(AttivitaList list);

// Permette di segnare l'attivita come completata
void SegnaCompletata(AttivitaList list, int id);

// Genere un report settimanale di tutte le attivita
void GeneraReportSettimanale(AttivitaList list);

// Fornisce un interfaccia grafica per interagire con il programma
void Menu(AttivitaList list);

#endif// ATTIVITA_LIST_H          // Fine del blocco di inclusione