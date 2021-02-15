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

extern Karte Kartenstapel[108];
extern int oberste_stapel_karte;
extern Karte letzte_karte;



