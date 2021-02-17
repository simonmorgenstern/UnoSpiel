#include "handkarten.h"


int anzahl_karten_spieler = 0;
int anzahl_karten_bot1 = 0;
int anzahl_karten_bot2 = 0;
int anzahl_karten_bot3 = 0;
int zieh_counter = 0;

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
    //zeige_handkarten_spieler();
}

// SM
void zeige_handkarten_spieler() {
    printf("\n Spielerkarten: \n");
    for (int i = 0; i < anzahl_karten_spieler; i++) {
        Karte k = p_handkarten_spieler[i];
        printf("Spielerkarte %d -> Typ: %d, Farbe: %d, Nummer: %d\n \n", i, k.typ, k.farbe, k.nummer);
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
            break;
        case bot2:
            printf("Bot2 zieht %d Karten \n", anzahl);
            p_handkarten_bot2 = realloc(p_handkarten_bot2, (anzahl_karten_bot2 + anzahl) * sizeof(Karte));
            for (int i = 0; i < anzahl; i++) {
                p_handkarten_bot2[anzahl_karten_bot2 + i] = Kartenstapel[oberste_stapel_karte];
                Kartenstapel[oberste_stapel_karte].status = inDerHand;
                oberste_stapel_karte++;
            }
            anzahl_karten_bot2 += anzahl;
            break;
        case bot3:
            printf("Bot3 zieht %d Karten \n", anzahl);
            p_handkarten_bot3 = realloc(p_handkarten_bot1, (anzahl_karten_bot3 + anzahl) * sizeof(Karte));
            for (int i = 0; i < anzahl; i++) {
                p_handkarten_bot3[anzahl_karten_bot3 + i] = Kartenstapel[oberste_stapel_karte];
                Kartenstapel[oberste_stapel_karte].status = inDerHand;
                oberste_stapel_karte++;
            }
            anzahl_karten_bot3 += anzahl;
            break;
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
            break;
        case bot2:
            for (int i = index; i < anzahl_karten_bot2 - 1; i++) {
                p_handkarten_bot2[i] = p_handkarten_bot2[i + 1];
            }
            p_handkarten_bot2 = realloc(p_handkarten_bot2, (anzahl_karten_bot2 - 1) * sizeof(Karte));
            anzahl_karten_bot2--;
            break;
        case bot3:
            for (int i = index; i < anzahl_karten_bot3 - 1; i++) {
                p_handkarten_bot3[i] = p_handkarten_bot3[i + 1];
            }
            p_handkarten_bot3 = realloc(p_handkarten_bot3, (anzahl_karten_bot3 - 1) * sizeof(Karte));
            anzahl_karten_bot3--;
            break;
        default:
            printf("Die Karte konnte nicht entfernt werden");
            break;
    }
}

void spielroutine_bot(int wer) {
    int *moegliche_karten = calloc(1, sizeof(int));
    int anzahl_moegliche_karten = 0;
    switch (wer) {
        case bot1:
            suche_moegliche_karten(p_handkarten_bot1, anzahl_karten_bot1, moegliche_karten, &anzahl_moegliche_karten);
            if (anzahl_moegliche_karten > 0) {
                // wähle random
                srand(time(NULL));
                int r = rand() % anzahl_moegliche_karten;
                int karten_index = moegliche_karten[r];
                if (p_handkarten_bot1[karten_index].typ == farbwunsch || p_handkarten_bot1[karten_index].typ == plus4) {
                    int farbe = meiste_karten_farbe(p_handkarten_bot1, anzahl_karten_bot1);
                    wuensche_farbe(farbe);
                }
                spiele_karte(bot1, karten_index);
            } else {
                if (zieh_counter > 0) {
                    ziehe_karten(bot1, zieh_counter);
                    zieh_counter = 0;
                } else {
                    ziehe_karten(bot1, 1);
                }
            }
            break;
        case bot2:
            suche_moegliche_karten(p_handkarten_bot2, anzahl_karten_bot2, moegliche_karten, &anzahl_moegliche_karten);
            if (anzahl_moegliche_karten > 0) {
                // wähle random
                srand(time(NULL));
                int r = rand() % anzahl_moegliche_karten;
                int karten_index = moegliche_karten[r];
                if (p_handkarten_bot2[karten_index].typ == farbwunsch || p_handkarten_bot2[karten_index].typ == plus4) {
                    int farbe = meiste_karten_farbe(p_handkarten_bot2, anzahl_karten_bot2);
                    wuensche_farbe(farbe);
                }
                spiele_karte(bot2, karten_index);
            } else {
                if (zieh_counter > 0) {
                    ziehe_karten(bot2, zieh_counter);
                    zieh_counter = 0;
                } else {
                    ziehe_karten(bot2, 1);
                }
            }
            break;
        case bot3:
            suche_moegliche_karten(p_handkarten_bot3, anzahl_karten_bot3, moegliche_karten, &anzahl_moegliche_karten);
            if (anzahl_moegliche_karten > 0) {
                srand(time(NULL));
                int r = rand() % anzahl_moegliche_karten;
                int karten_index = moegliche_karten[r];
                if (p_handkarten_bot3[karten_index].typ == farbwunsch || p_handkarten_bot3[karten_index].typ == plus4) {
                    int farbe = meiste_karten_farbe(p_handkarten_bot3, anzahl_karten_bot3);
                    wuensche_farbe(farbe);
                }
                spiele_karte(bot3, karten_index);
            } else {
                if (zieh_counter > 0) {
                    ziehe_karten(bot3, zieh_counter);
                    zieh_counter = 0;
                } else {
                    ziehe_karten(bot3, 1);
                }
            }
            break;
    }
    free(moegliche_karten);
}

void suche_moegliche_karten(Karte *handkarten, int karten_anzahl, int *moegliche_karten, int *anzahl_moegliche_karten) {
    for (int i = 0; i < karten_anzahl; i++) {
        if (pruefe_karte(handkarten[i]) == 1) {
            *anzahl_moegliche_karten = *anzahl_moegliche_karten + 1;
            moegliche_karten = realloc(moegliche_karten, (*anzahl_moegliche_karten * sizeof(int)));
            moegliche_karten[*anzahl_moegliche_karten - 1] = i;
        }
    }
}

int pruefe_karte(Karte pruef_karte) {
//    printf("Letzte Karte -> Typ: %d, Farbe: %d, Nummer: %d \n", letzte_karte.typ, letzte_karte.farbe, letzte_karte.nummer);
//    printf("Pruefkarte -> Typ: %d, Farbe: %d, Nummer: %d\n \n", pruef_karte.typ, pruef_karte.farbe, pruef_karte.nummer); // Testausgaben
    switch (letzte_karte.typ) {
        case zahl:
            if (letzte_karte.farbe == pruef_karte.farbe || letzte_karte.nummer == pruef_karte.nummer) {
                return 1;
            }
            return 0;
        case plus2:
            if (pruef_karte.typ == plus2 || pruef_karte.typ == plus4) {
                return 1;
            }
            return 0;
        case plus4:
            if (pruef_karte.typ == plus4 || (pruef_karte.typ == plus2 && pruef_karte.farbe == wunschfarbe)) {
                return 1;
            }
            return 0;
        case aussetzen:
            if (pruef_karte.typ == aussetzen || letzte_karte.farbe == pruef_karte.farbe) {
                return 1;
            }
            return 0;
        case richtungswechsel:
            if (pruef_karte.typ == richtungswechsel || letzte_karte.farbe == pruef_karte.farbe) {
                return 1;
            }
            return 0;
        case farbwunsch:
            if (pruef_karte.farbe == wunschfarbe) {
                return 1;
            }
            return 0;
        default:
            printf("Diesen Kartentypen gibt es leider nicht");
    }
}

int meiste_karten_farbe(Karte *handkarten, int karten_anzahl) {
    int max_farbe;
    int max_anzahl_aktuell = 0;
    int max_anzahl_vorher = 0;
    for (int i = 0; i < karten_anzahl; i++) {
        if (handkarten[i].farbe == blau) {
            max_anzahl_aktuell++;
        }
    }
    max_anzahl_vorher = max_anzahl_aktuell;
    max_anzahl_aktuell = 0;
    max_farbe = blau;
    for (int i = 0; i < karten_anzahl; i++) {
        if (handkarten[i].farbe == rot) {
            max_anzahl_aktuell++;
        }
    }
    if (max_anzahl_aktuell > max_anzahl_vorher) {
        max_farbe = rot;
    }
    max_anzahl_vorher = max_anzahl_aktuell;
    max_anzahl_aktuell = 0;
    for (int i = 0; i < karten_anzahl; i++) {
        if (handkarten[i].farbe == gelb) {
            max_anzahl_aktuell++;
        }
    }
    if (max_anzahl_aktuell > max_anzahl_vorher) {
        max_farbe = gelb;
    }
    max_anzahl_vorher = max_anzahl_aktuell;
    max_anzahl_aktuell = 0;
    for (int i = 0; i < karten_anzahl; i++) {
        if (handkarten[i].farbe == gruen) {
            max_anzahl_aktuell++;
        }
    }
    if (max_anzahl_aktuell > max_anzahl_vorher) {
        max_farbe = gruen;
    }
    return max_farbe;
}

void wuensche_farbe(int farbe) {
    wunschfarbe = farbe;
}

void aendere_spielrichtung() {
    if (spiel_richtung == rechts) {
        spiel_richtung = links;
    } else {
        spiel_richtung = rechts;
    }
}

void spiele_karte(int wer, int index) {
    switch (wer) {
        case bot1:
            letzte_karte = p_handkarten_bot1[index];
            Kartenstapel[p_handkarten_bot1[index].index].status = abgelegt;
            switch (p_handkarten_bot1[index].typ) {
                case plus4:
                    zieh_counter += 4;
                    break;
                case plus2:
                    zieh_counter += 2;
                    break;
                case richtungswechsel:
                    aendere_spielrichtung();
                    break;
            }
            entferne_karte(bot1, index);
            break;
        case bot2:
            letzte_karte = p_handkarten_bot2[index];
            Kartenstapel[p_handkarten_bot2[index].index].status = abgelegt;
            switch (p_handkarten_bot2[index].typ) {
                case plus4:
                    zieh_counter += 4;
                    break;
                case plus2:
                    zieh_counter += 2;
                    break;
                case richtungswechsel:
                    aendere_spielrichtung();
                    break;
            }
            entferne_karte(bot2, index);
            break;
        case bot3:
            letzte_karte = p_handkarten_bot3[index];
            Kartenstapel[p_handkarten_bot3[index].index].status = abgelegt;
            switch (p_handkarten_bot3[index].typ) {
                case plus4:
                    zieh_counter += 4;
                    break;
                case plus2:
                    zieh_counter += 2;
                    break;
                case richtungswechsel:
                    aendere_spielrichtung();
                    break;
            }
            entferne_karte(bot3, index);
            break;
        default:
            printf("spieler wurde nicht gefunden");
            break;
    }
}









