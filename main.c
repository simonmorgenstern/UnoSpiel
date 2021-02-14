#include <stdio.h>
#include "kartendeck.h"
#include "handkarten.h"
enum {spieler, bot1, bot2, bot3};
enum k_farbe{ blau, rot, gruen, gelb, schwarz };
enum richtung{links, rechts};
// Statusvariablen Spiel
Karte letzteKarte;
int spiel_richtung = rechts;
int zieh_counter = 0;
int wunschfarbe;
int spieler_reihenfolge[4] = {spieler, bot1, bot2, bot3};
int aktueller_spieler = spieler;

int main() {
    mische_karten();
    hole_handkarten_speicher();
    teile_karten_aus();
    zeige_handkarten_spieler();
    return 0;
}
