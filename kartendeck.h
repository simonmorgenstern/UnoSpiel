// SM
enum k_status{ inDerHand, aufDemStapel, abgelegt };
enum k_typ{ zahl, plus2, plus4, aussetzen, richtungswechsel, farbwunsch };
enum k_farbe{ blau, rot, gruen, gelb, schwarz };

void mische_karten();

typedef struct{
	int index; 
	int status;
	int typ;
	int nummer;
	int farbe;
} Karte;

extern Karte Kartenstapel[108];




