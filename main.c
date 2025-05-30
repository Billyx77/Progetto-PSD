#include <stdio.h>                      // Inclusione della libreria standard per I/O
#include <stdlib.h>                     // Inclusione della libreria standard per l'allocazione di memoria
#include <string.h>                     // Inclusione della libreria per le operazioni sulle stringhe
#include "attivita_list.h"              // Inclusione dell'header per le funzioni della lista delle attivita
#include "attivita.h"                   // Inclusione dell'header per la struttura Attivita

int main() {
    AttivitaList list = NuovaAttivitaList();

    // === 1. Verifica inserimento attività ===
    Attivita a1 = {1, "Progetto", "PSD", "2025/06/10", "3", 1, false};
    Attivita a2 = {2, "Esercizio", "MMI", "2025/06/08", "2", 2, false};
    Attivita a3 = {3, "Problema", "AM", "2025/06/15", "4", 3, false};

    AggiungiAttivita(list, a1);
    AggiungiAttivita(list, a2);
    AggiungiAttivita(list, a3);

    printf("\n>>> [TEST 1] Visualizzazione attivita dopo inserimento:\n");
    VisualizzaAttivita(list);

    // === 2. Test aggiornamento progresso ===
    printf("\n>>> [TEST 2] Modifica attivita: riduco ore di a2 (ID = 2)...\n");
    Attivita* att = TrovaAttivitaPerId(list, 2);
    if (att != NULL) {
        int ore_attuali;
        sscanf(att->tempo_stimato, "%dh", &ore_attuali);
        int ore_da_sottrarre = 2;
        ore_attuali -= ore_da_sottrarre;

        if (ore_attuali <= 0) {
            printf("Attivita completata!\n");
            att->completata = true;
            att->tempo_stimato[0] = '0';
            att->tempo_stimato[1] = 'h';
            att->tempo_stimato[2] = '\0';
        } else {
            printf("Attivita in corso. Ore rimanenti: %d\n", ore_attuali);
            if (ore_attuali < 10) {
                att->tempo_stimato[0] = '0' + ore_attuali;
                att->tempo_stimato[1] = 'h';
                att->tempo_stimato[2] = '\0';
            } else {
                // gestire eventuale errore se ore_attuali >= 10 con buffer troppo piccolo
                printf("Errore: ore rimanenti troppo grandi per tempo_stimato\n");
            }
        }
    }

    printf("\n>>> [TEST 2] Stato aggiornato:\n");
    VisualizzaAttivita(list);

    // === 3. Verifica generazione report settimanale ===
    printf("\n>>> [TEST 3] Report tra 2025/06/01 e 2025/06/12:\n");
    GeneraReportSettimanale(list, "2025/06/01", "2025/06/12");

    Menu(list);
    
    return 0;
}
