#include "handkarten.h"


int anzahl_karten_spieler = 0;
int anzahl_karten_bot1 = 0;
int anzahl_karten_bot2 = 0;
int anzahl_karten_bot3 = 0;

// SM
void hole_handkarten_speicher() {
    p_handkarten_spieler = calloc(7, sizeof(Karte));
    if (p_handkarten_spieler == NULL) {
        printf("Speicheranforderung fehlgeschlagen");
    }
    p_handkarten_bot1 = calloc(7, sizeof(Karte));
    if (p_handkarten_bot1 == NULL) {
        printf("Speicheranforderung fehlgeschlagen");
    }
    p_handkarten_bot2 = calloc(7, sizeof(Karte));
    if (p_handkarten_bot2 == NULL) {
        printf("Speicheranforderung fehlgeschlagen");
    }
    p_handkarten_bot3 = calloc(7, sizeof(Karte));
    if (p_handkarten_bot3 == NULL) {
        printf("Speicheranforderung fehlgeschlagen");
    }
}
// SM
void teile_karten_aus() {
    for (int karte = 0; karte < 7; karte++) {
        for (int spieler = 0; spieler < 4; spieler++) {
            int index = karte * 4 + spieler;
            switch (spieler) {
                case 0:
                    p_handkarten_spieler[karte] = Kartenstapel[index];
                    anzahl_karten_spieler++;
                    break;
                case 1:
                    p_handkarten_bot1[karte] = Kartenstapel[index];
                    anzahl_karten_bot1++;
                    break;
                case 2:
                    p_handkarten_bot2[karte] = Kartenstapel[index];
                    anzahl_karten_bot2++;
                    break;
                case 3:
                    p_handkarten_bot3[karte] = Kartenstapel[index];
                    anzahl_karten_bot3++;
                    break;
            }
            Kartenstapel[index].status = inDerHand;
            oberste_stapel_karte = index + 1;
        }
    }
}
// SM
void zeige_handkarten_spieler() {
    for(int i = 0; i < 7; i++){
        Karte k = p_handkarten_spieler[i];
        printf("%d -", k.index);
    }
}



