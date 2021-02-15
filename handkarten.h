#ifndef hand_karten_never_used
#define hand_karten_never_used

#include <stdio.h>
#include "kartendeck.h"
#include <stdlib.h>

void hole_handkarten_speicher();
void teile_karten_aus();
void zeige_handkarten_spieler();

Karte *p_handkarten_spieler;
Karte *p_handkarten_bot1;
Karte *p_handkarten_bot2;
Karte *p_handkarten_bot3;

#endif
void ziehe_karten(int wer, int anzahl);
void entferne_karte(int wer, int index);
