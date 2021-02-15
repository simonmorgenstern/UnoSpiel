#ifndef karten_deck_never_used
#define karten_deck_never_used
#include <stdio.h>
#include <stdlib.h>
// SM
void mische_karten();

typedef struct{
	int index; 
	int status;
	int typ;
	int nummer;
	int farbe;
} Karte;

Karte Kartenstapel[108];
int oberste_stapel_karte;

enum k_status{ inDerHand, aufDemStapel, abgelegt };
enum k_typ{ zahl, plus2, plus4, aussetzen, richtungswechsel, farbwunsch };
enum k_farbe{ blau, rot, gruen, gelb, schwarz };

void kopiere_karten();
void mische_karten();
void zeige_kartenstapel();

#endif
