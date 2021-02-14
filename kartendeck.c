#include <stdio.h>
#include <stdlib.h>
enum k_status{ inDerHand, aufDemStapel, abgelegt };
enum k_typ{ zahl, plus2, plus4, aussetzen, richtungswechsel, farbwunsch };
enum k_farbe{ blau, rot, gruen, gelb, schwarz };

void kopiere_karten();
void mische_karten();
void zeige_kartenstapel();

typedef struct {
	int index; 
	int status;
	int typ;
	int nummer;
	int farbe;
} Karte;

Karte Kartenstapel[108];
int oberste_stapel_karte;
Karte letzte_karte;
// SM
Karte Kartendeck[108] = {
	{0, aufDemStapel, zahl, 0, blau},
	{1, aufDemStapel, zahl, 1, blau},
	{2, aufDemStapel, zahl, 2, blau},
	{3, aufDemStapel, zahl, 3, blau},
	{4, aufDemStapel, zahl, 4, blau},
	{5, aufDemStapel, zahl, 5, blau},
	{6, aufDemStapel, zahl, 6, blau},
	{7, aufDemStapel, zahl, 7, blau},
	{8, aufDemStapel, zahl, 8, blau},	
	{9, aufDemStapel, zahl, 9, blau},	
	{10, aufDemStapel, zahl, 1, blau},
	{11, aufDemStapel, zahl, 2, blau},
	{12, aufDemStapel, zahl, 3, blau},
	{13, aufDemStapel, zahl, 4, blau},
	{14, aufDemStapel, zahl, 5, blau},
	{15, aufDemStapel, zahl, 6, blau},
	{16, aufDemStapel, zahl, 7, blau},
	{17, aufDemStapel, zahl, 8, blau},	
	{18, aufDemStapel, zahl, 9, blau},	
	{19, aufDemStapel, zahl, 0, rot},
	{20, aufDemStapel, zahl, 1, rot},
	{21, aufDemStapel, zahl, 2, rot},
	{22, aufDemStapel, zahl, 3, rot},
	{23, aufDemStapel, zahl, 4, rot},
	{24, aufDemStapel, zahl, 5, rot},
	{25, aufDemStapel, zahl, 6, rot},
	{26, aufDemStapel, zahl, 7, rot},
	{27, aufDemStapel, zahl, 8, rot},	
	{28, aufDemStapel, zahl, 9, rot},	
	{29, aufDemStapel, zahl, 1, rot},
	{30, aufDemStapel, zahl, 2, rot},
	{31, aufDemStapel, zahl, 3, rot},
	{32, aufDemStapel, zahl, 4, rot},
	{33, aufDemStapel, zahl, 5, rot},
	{34, aufDemStapel, zahl, 6, rot},
	{35, aufDemStapel, zahl, 7, rot},
	{36, aufDemStapel, zahl, 8, rot},	
	{37, aufDemStapel, zahl, 9, rot},	
	{38, aufDemStapel, zahl, 0, gruen},
	{39, aufDemStapel, zahl, 1, gruen},
	{40, aufDemStapel, zahl, 2, gruen},
	{41, aufDemStapel, zahl, 3, gruen},
	{42, aufDemStapel, zahl, 4, gruen},
	{43, aufDemStapel, zahl, 5, gruen},
	{44, aufDemStapel, zahl, 6, gruen},
	{45, aufDemStapel, zahl, 7, gruen},
	{46, aufDemStapel, zahl, 8, gruen},	
	{47, aufDemStapel, zahl, 9, gruen},
	{48, aufDemStapel, zahl, 1, gruen},
	{49, aufDemStapel, zahl, 2, gruen},
	{50, aufDemStapel, zahl, 3, gruen},
	{51, aufDemStapel, zahl, 4, gruen},
	{52, aufDemStapel, zahl, 5, gruen},
	{53, aufDemStapel, zahl, 6, gruen},
	{54, aufDemStapel, zahl, 7, gruen},
	{55, aufDemStapel, zahl, 8, gruen},	
	{56, aufDemStapel, zahl, 9, gruen},	
	{57, aufDemStapel, zahl, 0, gelb},
	{58, aufDemStapel, zahl, 1, gelb},
	{59, aufDemStapel, zahl, 2, gelb},
	{60, aufDemStapel, zahl, 3, gelb},
	{61, aufDemStapel, zahl, 4, gelb},
	{62, aufDemStapel, zahl, 5, gelb},
	{63, aufDemStapel, zahl, 6, gelb},
	{64, aufDemStapel, zahl, 7, gelb},
	{65, aufDemStapel, zahl, 8, gelb},	
	{66, aufDemStapel, zahl, 9, gelb},	
	{67, aufDemStapel, zahl, 1, gelb},
	{68, aufDemStapel, zahl, 2, gelb},
	{69, aufDemStapel, zahl, 3, gelb},
	{70, aufDemStapel, zahl, 4, gelb},
	{71, aufDemStapel, zahl, 5, gelb},
	{72, aufDemStapel, zahl, 6, gelb},
	{73, aufDemStapel, zahl, 7, gelb},
	{74, aufDemStapel, zahl, 8, gelb},	
	{75, aufDemStapel, zahl, 9, gelb},	
	{76, aufDemStapel, plus2, 10, blau},
	{77, aufDemStapel, plus2, 10, blau},
	{78, aufDemStapel, plus2, 10, rot},
	{79, aufDemStapel, plus2, 10, rot},	
	{80, aufDemStapel, plus2, 10, gruen},
	{81, aufDemStapel, plus2, 10, gruen},	
	{82, aufDemStapel, plus2, 10, gelb},
	{83, aufDemStapel, plus2, 10, gelb},	
	{84, aufDemStapel, aussetzen, 10, blau},
	{85, aufDemStapel, aussetzen, 10, blau},
	{86, aufDemStapel, aussetzen, 10, rot},
	{87, aufDemStapel, aussetzen, 10, rot},	
	{88, aufDemStapel, aussetzen, 10, gruen},
	{89, aufDemStapel, aussetzen, 10, gruen},	
	{90, aufDemStapel, aussetzen, 10, gelb},
	{91, aufDemStapel, aussetzen, 10, gelb},	
	{92, aufDemStapel, richtungswechsel, 10, blau},
	{93, aufDemStapel, richtungswechsel, 10, blau},
	{94, aufDemStapel, richtungswechsel, 10, rot},
	{95, aufDemStapel, richtungswechsel, 10, rot},	
	{96, aufDemStapel, richtungswechsel, 10, gruen},
	{97, aufDemStapel, richtungswechsel, 10, gruen},	
	{98, aufDemStapel, richtungswechsel, 10, gelb},
	{99, aufDemStapel, richtungswechsel, 10, gelb},	
	{100, aufDemStapel, farbwunsch, 10, schwarz},
	{101, aufDemStapel, farbwunsch, 10, schwarz},
	{102, aufDemStapel, farbwunsch, 10, schwarz},
	{103, aufDemStapel, farbwunsch, 10, schwarz},	
	{104, aufDemStapel, farbwunsch, 10, schwarz},
	{105, aufDemStapel, farbwunsch, 10, schwarz},
	{106, aufDemStapel, farbwunsch, 10, schwarz},
	{107, aufDemStapel, farbwunsch, 10, schwarz}
};	

void mische_karten() {
	kopiere_karten();
	size_t i;
    for (i = 0; i < 108 - 1; i++) {
        size_t j = i + rand() / (RAND_MAX / (108 - i) + 1);
        Karte k = Kartenstapel[j];
        Kartenstapel[j] = Kartenstapel[i];
        Kartenstapel[i] = k;
        Kartenstapel[i].index = i;
        Kartenstapel[j].index = j;
    }
    // zeige_kartenstapel(); // method for testing
}

// SM 
void kopiere_karten() {
	for(int i = 0; i < 108; i++){
		Kartenstapel[i] = Kartendeck[i];	
	}
}

// SM
void decke_auf() {
    letzte_karte = Kartenstapel[oberste_stapel_karte];
    Kartenstapel[oberste_stapel_karte].status = abgelegt;
    oberste_stapel_karte++;
}

// SM | Testmethode
void zeige_kartenstapel() {
	for(int i = 0; i < 108; i++){
		printf("%d -", Kartenstapel[i].index);
	}
}










	
