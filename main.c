#include <stdio.h>
#include "kartendeck.h"
#include "handkarten.h"
#include "menue.h"
#include "ende.h"                    //eingefügt




// Statusvariablen Spiel

int spiel_richtung = rechts;
int spieler_reihenfolge[4] = {spieler, bot1, bot2, bot3};
int aktueller_spieler = spieler;
int spielstatus = start;

int main() {
    if (spielstart() == 1) {
        do {
            init_spiel();
            spiel_schleife();
        } while (spiel_ende_benachrichtigung() == 1);
    }

    return 0;
}

void spiel_schleife() {
    decke_auf();
    spielstatus = spiel;
    do {
        switch(spieler_reihenfolge[aktueller_spieler]){
            case spieler:
                printf("Du bist dran.");
                spielroutine_spieler();
                //printf("DEBUG Spiel_schleife Ende Spielercase\n");
                break;
            case bot1:
				//printf("DEBUG Spiel_schleife Soerencase\n");
                printf("Soeren ist dran.\n");
                spielroutine_bot(bot1);
                pause(2);
                break;
            case bot2:
                printf("Brigitte ist dran.\n");
                spielroutine_bot(bot2);
                pause(2);
                break;
            case bot3:
                printf("Guenther ist dran.\n");
                spielroutine_bot(bot3);
                pause(2);
                break;
            default:
                printf("Kann spieler nicht finden.\n");
        }
        if(anzahl_karten_spieler == 0 || anzahl_karten_bot1 == 0 || anzahl_karten_bot2 == 0 || anzahl_karten_bot3 == 0){
            spielstatus = spielende;
            if (anzahl_karten_bot1 == 0){
				printf("Soeren hat gewonnen.\n\n");
				pause(2);
			}
			if (anzahl_karten_bot2 == 0){
				printf("Brigitte hat gewonnen.\n\n");
				pause(2);	
			}
			if (anzahl_karten_bot3 == 0){
				printf("Guenther hat gewonnen.\n\n");
				pause(2);	
			}
        }
    }while (spielstatus == spiel);
    //printf("Spiel Ende \n");
    // Spielende Funktion wird aufgerufen
    // Abfrage ob erneut gespielt werden soll
}

void init_spiel() {
    mische_karten();
    hole_handkarten_speicher();
    teile_karten_aus();
}

// Linux 1000000 | Windoof 1000
void pause(int nummer_sekunden)
{
    int millisekunden = 100000 * nummer_sekunden;
    clock_t start_zeit = clock();
    while (clock() < start_zeit + millisekunden);
}
