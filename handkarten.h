#ifndef hand_karten_never_used
#define hand_karten_never_used

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "kartendeck.h"
#include "main.h"


void hole_handkarten_speicher();
void teile_karten_aus();
void zeige_handkarten_spieler();
void ziehe_karten(int wer, int anzahl);
void entferne_karte(int wer, int index);
void spielroutine_bot(int wer);
void spielroutine_spieler();
void suche_moegliche_karten(Karte *handkarten, int karten_anzahl, int *moegliche_karten, int *anzahl_moegliche_karten);
int pruefe_karte(Karte pruef_karte);
int meiste_karten_farbe(Karte *handkarten, int karten_anzahl);
int gib_farbe(char *a);
int gib_funktion(char *b, int *c);
void wuensche_farbe(int farbe);
void wuensche_farbe_spieler();
void spiele_karte(int wer, int index);
void aendere_spielrichtung();
void naechster_spieler(int schritte);

Karte *p_handkarten_spieler;
Karte *p_handkarten_bot1;
Karte *p_handkarten_bot2;
Karte *p_handkarten_bot3;

int anzahl_karten_spieler;
int anzahl_karten_bot1;
int anzahl_karten_bot2;
int anzahl_karten_bot3;
int zieh_counter;



#endif
