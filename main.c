#include <stdio.h>
#include "kartendeck.h"
#include "handkarten.h"
#include "menue.h"
#include "ende.h"					//eingefügt


void init_spiel();
void spiel_schleife();

enum {spieler, bot1, bot2, bot3};
enum richtung{links, rechts};
enum {start, spiel, spielende};

// Statusvariablen Spiel

int spiel_richtung = rechts;
int zieh_counter = 0;
int wunschfarbe;
int spieler_reihenfolge[4] = {spieler, bot1, bot2, bot3};
int aktueller_spieler = spieler;
int spielstatus = start;

int main() {
    if(spielstart() == 1){
		do{
			init_spiel();
			spiel_schleife();
		}
		while (spiel_ende_benachrichtigung() == 1);
    }

    return 0;
}

void spiel_schleife(){
    decke_auf();
    spielstatus = spiel;
    while(spielstatus == spiel){
        break;
        // Hier finden alle Spielzüge statt
        // Prüfen ob einer gewonnen hat
    }
    printf("Spiel Ende \n");
    // Spielende Funktion wird aufgerufen
    // Abfrage ob erneut gespielt werden soll
}

void init_spiel(){
    mische_karten();
    hole_handkarten_speicher();
    teile_karten_aus();
}

