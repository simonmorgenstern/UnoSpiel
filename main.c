#include <stdio.h>
#include "kartendeck.h"
#include "handkarten.h"
#include "menue.h"
#include "ende.h"                    //eingefügt




// Statusvariablen Spiel

int spiel_richtung = rechts;
int spieler_reihenfolge[4] = {spieler, bot1, bot2, bot3};
int aktueller_spieler = bot1;
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
    while (spielstatus == spiel) {
        switch(spieler_reihenfolge[aktueller_spieler]){
            case spieler:
                // Spielroutine Spieler
                spielroutine_spieler();
                break;
            case bot1:
                printf("bot 1 ist dran \n");
                spielroutine_bot(bot1);
                break;
            case bot2:
                printf("bot 2 ist dran \n");
                spielroutine_bot(bot2);
                break;
            case bot3:
                printf("bot 3 ist dran \n");
                spielroutine_bot(bot3);
                break;
        }
        if(anzahl_karten_spieler == 0 || anzahl_karten_bot1 == 0 || anzahl_karten_bot2 == 0 || anzahl_karten_bot3 == 0){
            spielstatus = spielende;
        }
    }
    printf("Spiel Ende \n");
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
    int millisekunden = 1000 * nummer_sekunden;
    clock_t start_zeit = clock();
    while (clock() < start_zeit + millisekunden);
}
