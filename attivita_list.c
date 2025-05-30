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
    AttivitaList list = malloc(sizeof(struct attivitaList));                    // Allocazione della memoria per la lista
    if (list != NULL) {                                                         // Se l'allocazione ha avuto successo
        list->head = NULL;                                                      // Inizializza la lista come vuota (head = NULL)
    }
    return list;                                                                // Restituisce il puntatore alla nuova lista
}

// Funzione: EmptyAttivitaList
// Verifica se la lista delle attivita e vuota
bool EmptyAttivitaList(AttivitaList list) {
    return (list == NULL || list->head == NULL);                                // La lista è vuota se il puntatore è NULL o se head è NULL
}

// Funzione: AggiungiAttivita
// Aggiunge una attivita in cima alla lista (inserimento in testa)
AttivitaList AggiungiAttivita(AttivitaList list, Attivita att) {
    if (list == NULL) return NULL;                                              // Se la lista è NULL, ritorna NULL (errore)
    Node* newNode = malloc(sizeof(Node));                                       // Allocazione di memoria per il nuovo nodo
    if (newNode == NULL) return list;                                           // Se l'allocazione fallisce, restituisce la lista invariata
    newNode->att = att;                                                         // Assegna l'attivita al nuovo nodo
    newNode->next = list->head;                                                 // Imposta il puntatore next del nuovo nodo al nodo attuale in testa
    list->head = newNode;                                                       // Aggiorna head della lista, facendo del nuovo nodo il primo elemento
    return list;                                                                // Restituisce la lista aggiornata
}

// Funzione: VisualizzaAttivita
// Permette di visualizzare tutte le attivita
void VisualizzaAttivita(AttivitaList list) {                                                                            
    Node* current = list->head;                                                                                         // Inizia dal nodo in testa
    printf("\n-- Attivita di Studio --\n");                                                                             
    while (current != NULL) {                                                                                           // Scorri tutta la lista
        printf("ID: %d | Descrizione: %s | Corso: %s | Scadenza: %s | Tempo: %sh | Priorita: %d | Stato: %s\n",         // Stampiamo tutte le informazioni dell'attività corrente
               current->att.id, 
               current->att.descrizione,
               current->att.corso,
               current->att.data_scadenza,
               current->att.tempo_stimato,
               current->att.priorita,
               current->att.completata ? "Completata" : "In corso");
        current = current->next;                                                                                        // Passa al nodo successivo
    }   
}

// Funzione: SegnaCompletata
// Permette di segnare l'attivita come completata
void SegnaCompletata(AttivitaList list, int id) {
    Node* current = list->head;                                                 // Inizia dal nodo in testa
    while (current != NULL) {                                                   // Scorri tutta la lista
        if (current->att.id == id) {                                            // Controlliamo se l'id corrisponde
            current->att.completata = true;                                     
            printf("Attivita %d segnata come completata.\n", id);               
            return;                                                             
        }
        current = current->next;                                                // Passa al nodo successivo
    }
    printf("Attivita con ID %d non trovata.\n", id);
}


// Funzione: DataCompresa
// Confronta le data per vedere quale è compresa
int DataCompresa(const char* data, const char* data_inizio, const char* data_fine) {
    return strcmp(data, data_inizio) >= 0 && strcmp(data, data_fine) <= 0;                      // Confrontiamo le date per vedere se è compresa
}

// Funzione: GeneraReportSettimanale
// Genera un report settimanale di tutte le attivita
void GeneraReportSettimanale(AttivitaList list, const char* data_inizio, const char* data_fine) {       
    Node* current = list->head;                                                                         // Inizia dal nodo in testa
    printf("\n--- Report Settimanale (%s - %s) ---\n", data_inizio, data_fine);                         

    while (current != NULL) {                                                                           // Scorri tutta la lista
        if (DataCompresa(current->att.data_scadenza, data_inizio, data_fine)) {                         // Confrontiamo le date
            printf("ID: %d | Corso: %s | Scadenza: %s | Stato: %s\n",                                   // Stampa dei dati
                   current->att.id,
                   current->att.corso,
                   current->att.data_scadenza,
                   current->att.completata ? "Completata" : "In ritardo o in corso");
        }
        current = current->next;                                                                        // Passa al nodo successivo
    }
}

// Funzione: TrovaAttivitaPerId
// Trova un'attivita in base all'id
Attivita* TrovaAttivitaPerId(AttivitaList list, int id) {               
    Node* current = list->head;                                         // Inizia dal nodo in testa
    while (current != NULL) {                                           // Scorri tutta la lista
        if (current->att.id == id) {                                    // Controlliamo se l'id corrisponde
            return &current->att;                                       // Restituisce un puntatore all'attività trovata nella lista
        }
        current = current->next;                                        // Passa al nodo successivo
    }
    return NULL;                                                        // Restituisce null
}

// Deallocazione della lista attivita
void DistruggiAttivitaList(AttivitaList list) {
    if (list == NULL) return;                                           // Se la lista è già NULL, non c'è nulla da liberare

    Node* current = list->head;                                         // Inizia dal nodo in testa
    while (current != NULL) {                                           // Scorri tutta la lista
        Node* temp = current;                                           // Salva il nodo corrente
        current = current->next;                                        // Passa al nodo successivo
        free(temp);                                                     // Libera il nodo salvato
    }

    free(list);                                                         // Alla fine libera anche la struttura principale della lista
}   

// Funzione: Menu
// Fornisce un interfaccia per interagire con il programma
void Menu(AttivitaList list) {
    int scelta;
    do {

        // Menu iniziale
        printf("\n1. Aggiungi attivita");
        printf("\n2. Segna completata");
        printf("\n3. Mostra attivita");
        printf("\n4. Report settimanale");
        printf("\n5. Modifica attivita");
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
                printf("Data scadenza (AAAA/MM/GG): "); 
                scanf("%s", a.data_scadenza);
                printf("Tempo stimato (es. 2h): "); 
                scanf("%s", a.tempo_stimato);
                printf("Priorita (1=alta, 2=media, 3=bassa): "); 
                scanf("%d", &a.priorita);
                a.completata = false;                                   // nuova attività non è ancora completata
                AggiungiAttivita(list, a);                              // aggiunge alla lista
                break;
            }

            case 2: {
                int id;
                printf("ID attivita da completare: ");
                scanf("%d", &id);
                SegnaCompletata(list, id);                              // cerca e segna come completata
                break;
            }

            case 3:
                VisualizzaAttivita(list);
                break;

            case 4:
                char data_inizio[11], data_fine[11]; 

                printf("Inserisci data inizio (AAAA/MM/GG): ");
                scanf("%10s", data_inizio);

                printf("Inserisci data fine (AAAA/MM/GG): ");
                scanf("%10s", data_fine);

                GeneraReportSettimanale(list, data_inizio, data_fine);
                break;

            
            case 5: {
                int id, oreDaSottrarre, ore_attuali;
                printf("Inserisci l'ID dell'attivita: ");
                scanf("%d", &id);

                Attivita* att = TrovaAttivitaPerId(list, id);           // Cerca l'attività tramite ID
                    if (att == NULL) {
                        printf("Attivita non trovata.\n");
                        break;
                    }

                sscanf(att->tempo_stimato, "%d", &ore_attuali);
                printf("Ore attuali: %d\n", ore_attuali);
                printf("Quante ore vuoi sottrarre? ");
                scanf("%d", &oreDaSottrarre);

                ore_attuali -= oreDaSottrarre;

                if (ore_attuali <= 0) {
                    printf("Attivita completata!\n");
                    att->completata = true;
                    strcpy(att->tempo_stimato, "0");
                } else {
                    printf("Attivita in corso. Ore rimanenti: %d\n", ore_attuali);
                    printf(att->tempo_stimato, "%d", ore_attuali);
                }

                break;
            }

            case 0:
                printf("Uscita dal programma.\n");
                DistruggiAttivitaList(list);                        // libera memoria
                break;

            default:
                printf("Scelta non valida. Riprova.\n");
        }

    } while (scelta != 0);
}
