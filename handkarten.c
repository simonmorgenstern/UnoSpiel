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
    printf("\n Spielerkarten: \n");
    for (int i = 0; i < anzahl_karten_spieler; i++) {
        Karte k = p_handkarten_spieler[i];
        printf("%d -", k.index);
    }
}

// SM
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
//            zeige_handkarten_spieler();
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

void entferne_karte(int wer, int index) {
    switch (wer) {
        case spieler:
            for (int i = index; i < anzahl_karten_spieler - 1; i++) {
                p_handkarten_spieler[i] = p_handkarten_spieler[i + 1];
            }
            p_handkarten_spieler = realloc(p_handkarten_spieler, (anzahl_karten_spieler - 1) * sizeof(Karte));
            anzahl_karten_spieler--;
            zeige_handkarten_spieler();
            break;
        case bot1:
            for (int i = index; i < anzahl_karten_bot1 - 1; i++) {
                p_handkarten_bot1[i] = p_handkarten_bot1[i + 1];
            }
            p_handkarten_bot1 = realloc(p_handkarten_bot1, (anzahl_karten_bot1 - 1) * sizeof(Karte));
            anzahl_karten_bot1--;
        case bot2:
            for (int i = index; i < anzahl_karten_bot2 - 1; i++) {
                p_handkarten_bot2[i] = p_handkarten_bot2[i + 1];
            }
            p_handkarten_bot2 = realloc(p_handkarten_bot2, (anzahl_karten_bot2 - 1) * sizeof(Karte));
            anzahl_karten_bot2--;
        case bot3:
            for (int i = index; i < anzahl_karten_bot3 - 1; i++) {
                p_handkarten_bot3[i] = p_handkarten_bot3[i + 1];
            }
            p_handkarten_bot3 = realloc(p_handkarten_bot3, (anzahl_karten_bot3 - 1) * sizeof(Karte));
            anzahl_karten_bot3--;
        default:
            printf("Die Karte konnte nicht entfernt werden");
            break;
    }
}

void spielroutine_bot(int wer) {
    switch (wer) {
        bot1:
            break;
        bot2:
            break;
        bot3:
            break;
    }
    // Ausgabe der Kartenzahl für den Spieler
}

void moegliche_karten(Karte *p_handkarten, int karten_anzahl, int *p_moegliche_karten) {
    for (int i = 0; i < karten_anzahl; i++) {
        // pruefe ob Karte moeglich ist
        // falls ja fuege index der Karte zum array p_moegliche_karten hinzu
    }
}

int pruefe_karte(Karte pruef_karte) {
    switch (letzte_karte.typ) {
        case zahl:
            if(letzte_karte.farbe == pruef_karte.farbe || letzte_karte.nummer == pruef_karte.nummer) {
                return 1;
            }
            return 0;
        case plus2:
            if(pruef_karte.typ == plus2) {
                return 1;
            }
            return 0;
        case plus4:
            return 1;
        case aussetzen:
            if(pruef_karte.typ == aussetzen || letzte_karte.farbe == pruef_karte.farbe){
                return 1;
            }
            return 0;
        case richtungswechsel:
            if(pruef_karte.typ == richtungswechsel || letzte_karte.farbe == pruef_karte.farbe) {
                return 1;
            }
            return 0;
        case farbwunsch:
            if(pruef_karte.farbe == wunschfarbe) {
                return 1;
            }
            return 0;
        default:
            printf("Diesen Kartentypen gibt es leider nicht");
    }
}





