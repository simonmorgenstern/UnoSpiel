#include <stdio.h>
#include "kartendeck.h"
#include "stdlib.h"

enum k_status {
    inDerHand, aufDemStapel, abgelegt
};
enum {
    spieler, bot1, bot2, bot3
};

void hole_handkarten_speicher();

void teile_karten_aus();

void zeige_handkarten_spieler();

void ziehe_karten(int wer, int anzahl);

Karte *p_handkarten_spieler;
Karte *p_handkarten_bot1;
Karte *p_handkarten_bot2;
Karte *p_handkarten_bot3;
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
        for (int spieler_counter = 0; spieler_counter < 4; spieler_counter++) {
            switch (spieler_counter) {
                case spieler:
                    p_handkarten_spieler[karte] = Kartenstapel[oberste_stapel_karte];
                    anzahl_karten_spieler++;
                    break;
                case bot1:
                    p_handkarten_bot1[karte] = Kartenstapel[oberste_stapel_karte];
                    anzahl_karten_bot1++;
                    break;
                case bot2:
                    p_handkarten_bot2[karte] = Kartenstapel[oberste_stapel_karte];
                    anzahl_karten_bot2++;
                    break;
                case bot3:
                    p_handkarten_bot3[karte] = Kartenstapel[oberste_stapel_karte];
                    anzahl_karten_bot3++;
                    break;
            }
            Kartenstapel[oberste_stapel_karte].status = inDerHand;
            oberste_stapel_karte++;
        }
    }
}

// SM
void zeige_handkarten_spieler() {
    for (int i = 0; i < anzahl_karten_spieler; i++) {
        Karte k = p_handkarten_spieler[i];
        printf("%d -", k.index);
    }
}

void ziehe_karten(int wer, int anzahl) {
    switch (wer) {
        case spieler:
            printf("Spieler zieht %d Karten \n", anzahl);
            p_handkarten_spieler = realloc(p_handkarten_spieler, (anzahl_karten_spieler + anzahl) * sizeof(Karte));
            for (int i = 0; i < anzahl; i++) {
                p_handkarten_spieler[anzahl_karten_spieler + i] = Kartenstapel[oberste_stapel_karte];
                Kartenstapel[oberste_stapel_karte].status = inDerHand;
                oberste_stapel_karte++;
            }
            anzahl_karten_spieler += anzahl;
            zeige_handkarten_spieler();
            break;
        case bot1:
            printf("Bot1 zieht %d Karten \n", anzahl);
            p_handkarten_bot1 = realloc(p_handkarten_bot1, (anzahl_karten_bot1 + anzahl) * sizeof(Karte));
            for (int i = 0; i < anzahl; i++) {
                p_handkarten_bot1[anzahl_karten_bot1 + i] = Kartenstapel[oberste_stapel_karte];
                Kartenstapel[oberste_stapel_karte].status = inDerHand;
                oberste_stapel_karte++;
            }
            anzahl_karten_bot1 += anzahl;
        case bot2:
            printf("Bot2 zieht %d Karten \n", anzahl);
            p_handkarten_bot2 = realloc(p_handkarten_bot2, (anzahl_karten_bot2 + anzahl) * sizeof(Karte));
            for (int i = 0; i < anzahl; i++) {
                p_handkarten_bot2[anzahl_karten_bot2 + i] = Kartenstapel[oberste_stapel_karte];
                Kartenstapel[oberste_stapel_karte].status = inDerHand;
                oberste_stapel_karte++;
            }
            anzahl_karten_bot2 += anzahl;
        case bot3:
            printf("Bot3 zieht %d Karten \n", anzahl);
            p_handkarten_bot3 = realloc(p_handkarten_bot1, (anzahl_karten_bot3 + anzahl) * sizeof(Karte));
            for (int i = 0; i < anzahl; i++) {
                p_handkarten_bot3[anzahl_karten_bot3 + i] = Kartenstapel[oberste_stapel_karte];
                Kartenstapel[oberste_stapel_karte].status = inDerHand;
                oberste_stapel_karte++;
            }
            anzahl_karten_bot3 += anzahl;
        default:
            printf("Es gab ein Fehler beim Ziehen der Karten");
            break;
    }
}





