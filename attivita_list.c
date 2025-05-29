#include <stdio.h>                   // Inclusione della libreria standard per I/O
#include <stdlib.h>                  // Inclusione della libreria standard per l'allocazione di memoria
#include <string.h>                  // Inclusione della libreria per le operazioni sulle stringhe
#include "attivita_list.h"           // Inclusione dell'header dell'ADT AttivitaList

// Definizione della struttura nodo per la lista concatenata
typedef struct node {
    Attivita att;                    // Campo dati: attvita memorizzata nel nodo
    struct node* next;               // Puntatore al nodo successivo
} Node;

// Definizione della struttura per la lista delle attivita
struct attivitaList {
    Node* head;                      // Puntatore al primo nodo della lista
};

// Funzione: NuovaAttivitaList
// Crea e restituisce una nuova lista delle attivita vuota
AttivitaList NuovaAttivitaList(void) {
    AttivitaList list = malloc(sizeof(struct attivitaList));
    if (list != NULL) {
        list->head = NULL;
    }
    return list;
}

// Funzione: EmptyAttivitaList
// Verifica se la lista delle attivita e vuota
bool EmptyAttivitaList(AttivitaList list) {
    return (list == NULL || list->head == NULL);
}

// Funzione: AggiungiAttivita
// Aggiunge una attivita in cima alla lista (inserimento in testa)
AttivitaList AggiungiAttivita(AttivitaList list, Attivita att) {
    if (list == NULL) return NULL;
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) return list;
    newNode->att = att;
    newNode->next = list->head;
    list->head = newNode;
    return list;
}

// Funzione: VisualizzaAttivita
// Permette di visualizzare tutte le attivita
void VisualizzaAttivita(AttivitaList list) {
    Node* current = list->head;
    printf("\n-- Attivita di Studio --\n");
    while (current != NULL) {
        printf("ID: %d | Descrizione: %s | Corso: %s | Scadenza: %s | Tempo: %s | Priorita: %d | Stato: %s\n",
               current->att.id,
               current->att.descrizione,
               current->att.corso,
               current->att.data_scadenza,
               current->att.tempo_stimato,
               current->att.priorita,
               current->att.completata ? "Completata" : "In corso");
        current = current->next;
    }
}

// Funzione: SegnaCompletata
// Permette di segnare l'attivita come completata
void SegnaCompletata(AttivitaList list, int id) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->att.id == id) {
            current->att.completata = true;
            printf("Attivita %d segnata come completata.\n", id);
            return;
        }
        current = current->next;
    }
    printf("Attivita con ID %d non trovata.\n", id);
}

// Funzione: GeneraReportSettimanale
// Genera un report settimanale di tutte le attivita
void GeneraReportSettimanale(AttivitaList list) {
    Node* current = list->head;
    printf("\n--- Report Settimanale ---\n");
    while (current != NULL) {
        printf("ID: %d | Corso: %s | Scadenza: %s | Stato: %s\n",
               current->att.id,
               current->att.corso,
               current->att.data_scadenza,
               current->att.completata ? "Completata" : "In ritardo o in corso");
        current = current->next;
    }
}

// Funzione: Menu
// Fornisce un interfaccia per interagire con il programma
void Menu(AttivitaList list) {
    int scelta;
    do {
        printf("\n1. Aggiungi attivita");
        printf("\n2. Segna completata");
        printf("\n3. Mostra attivita");
        printf("\n4. Report settimanale");
        printf("\n0. Esci\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                Attivita a;
                printf("ID: "); 
                scanf("%d", &a.id);
                printf("Descrizione: "); 
                scanf("%s", a.descrizione);
                printf("Corso: "); 
                scanf("%s", a.corso);
                printf("Data scadenza (gg/mm/aaaa): "); 
                scanf("%s", a.data_scadenza);
                printf("Tempo stimato (es. 2h): "); 
                scanf("%s", a.tempo_stimato);
                printf("Priorita (1=alta, 2=media, 3=bassa): "); 
                scanf("%d", &a.priorita);
                a.completata = false;
                AggiungiAttivita(list, a);
                break;
            }

            case 2: {
                int id;
                printf("ID attivita da completare: ");
                scanf("%d", &id);
                SegnaCompletata(list, id);
                break;
            }

            case 3:
                VisualizzaAttivita(list);
                break;

            case 4:
                GeneraReportSettimanale(list);
                break;

            case 0:
                printf("Uscita dal programma.\n");
                break;

            default:
                printf("Scelta non valida. Riprova.\n");
        }

    } while (scelta != 0);
}