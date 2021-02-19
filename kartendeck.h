#ifndef karten_deck_never_used
#define karten_deck_never_used
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

// SM
void mische_karten();
void decke_auf();

typedef struct{
	int index; 
	int status;
	int typ;
	int nummer;
	int farbe;
} Karte;

Karte Kartenstapel[108];
int oberste_stapel_karte;
Karte letzte_karte;
int wunschfarbe;


enum k_status{ inDerHand, aufDemStapel, abgelegt };
enum k_typ{ zahl, plus2, plus4, aussetzen, richtungswechsel, farbwunsch };
enum k_farbe{ blau, rot, gruen, gelb, schwarz };

char karten_uebersetzung_farbe[5][8];
char karten_uebersetzung_typ[6][18];


void kopiere_karten();
void mische_karten();
void zeige_kartenstapel();
void tausche_karten(Karte *a, Karte *b);
void mischen();

#endif
