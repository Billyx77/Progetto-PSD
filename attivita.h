#ifndef ATTIVITA_H                          // Inizio del blocco di inclusione
#define ATTIVITA_H                          // Definizione della macro per evitare inclusioni multiple

#define MAX_DESCRIZIONE 30                 // Definizione della lunghezza massima per la descrizione
#define MAX_CORSO 20                       // Definizione della lunghezza massima per il corso
#define MAX_DATA 11                        // Definizione della lunghezza massima per la data di scadenza
#define MAX_TEMPO 2                        // Definizione della lunghezza massima per il tempo stimato

// Definizione della struttura Attivita, che rappresenta una attivita
typedef struct {
    int id;                                // Identificativo univoco dell'attivita
    char descrizione[MAX_DESCRIZIONE];     // Descrizione dell'attivita (max 30 caratteri)
    char corso[MAX_CORSO];                 // Nome del corso (max 20 caratteri)
    char data_scadenza[MAX_DATA];          // Data dell'attivita (max 11 caratteri) GG/MM/AAAA
    char tempo_stimato[MAX_TEMPO];         // Tempo stimato per completare l'attivita (max 2 caratteri) HH
    int priorita;                          // Priorita dell'attivita  1 = alta, 2 = media, 3 = bassa
    bool completata;                       // Variabile per completare una attivita
} Attivita;

// Dichiarazione della costante NULL_ATTIVITA, usata per rappresentare un'attivita "nulla"
extern const Attivita NULL_ATTIVITA;

#endif// ATTIVITA_H                // Fine del blocco di inclusione
