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
        printf("Speicheranforderung fehlgeschlagen\n");
    }
    p_handkarten_bot1 = calloc(7, sizeof(Karte));
    if (p_handkarten_bot1 == NULL) {
        printf("Speicheranforderung fehlgeschlagen\n");
    }
    p_handkarten_bot2 = calloc(7, sizeof(Karte));
    if (p_handkarten_bot2 == NULL) {
        printf("Speicheranforderung fehlgeschlagen\n");
    }
    p_handkarten_bot3 = calloc(7, sizeof(Karte));
    if (p_handkarten_bot3 == NULL) {
        printf("Speicheranforderung fehlgeschlagen\n");
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
    printf("Der Gamemaster teilt die Karten aus.\n");
    printf(".\n");
    pause(1);
    printf("..\n");
    pause(1);
    printf("...\n");
    pause(1);
    //zeige_handkarten_spieler();
}

// SM SL
void zeige_handkarten_spieler() {
    printf("\nDu hast folgende Karten auf deiner Hand: \n");
    printf("Karte -> Farbe:   Nummer:  Typ: \n");
    for (int i = 0; i < anzahl_karten_spieler; i++) {                    //verschönern!!!//SL, bessere Darstellung
        Karte k = p_handkarten_spieler[i];
        int j = i + 1;
        printf("%-5d -> %-7s  %-7d  %s\n", j, karten_uebersetzung_farbe[k.farbe], k.nummer,
               karten_uebersetzung_typ[k.typ]);
    }
}


// SM
void ziehe_karten(int wer, int anzahl) {
    switch (wer) {
        case spieler:
            //printf("Du musst %d Karte(n) ziehen.\n", anzahl);
            p_handkarten_spieler = (Karte *) realloc(p_handkarten_spieler, (anzahl_karten_spieler + anzahl) * sizeof(Karte));
            if (p_handkarten_spieler == NULL) {
                printf("Speicheranforderung fehlgeschlagen bei ziehe_karten\n");
            } else {
                for (int i = 0; i < anzahl; i++) {
                    p_handkarten_spieler[anzahl_karten_spieler] = Kartenstapel[oberste_stapel_karte];
                    Kartenstapel[oberste_stapel_karte].status = inDerHand;
                    oberste_stapel_karte++;
                    anzahl_karten_spieler++;
                }
            }
            break;
        case bot1:
            p_handkarten_bot1 = (Karte *) realloc(p_handkarten_bot1, (anzahl_karten_bot1 + anzahl) * sizeof(Karte));
            if (p_handkarten_bot1 == NULL) {
                printf("Speicheranforderung fehlgeschlagen bei ziehe_karten\n");
            } else {
                for (int i = 0; i < anzahl; i++) {
                    p_handkarten_bot1[anzahl_karten_bot1] = Kartenstapel[oberste_stapel_karte];
                    Kartenstapel[oberste_stapel_karte].status = inDerHand;
                    oberste_stapel_karte++;
                    anzahl_karten_bot1++;
                }
            }
            break;
        case bot2:
            p_handkarten_bot2 = (Karte *) realloc(p_handkarten_bot2, (anzahl_karten_bot2 + anzahl) * sizeof(Karte));
            if (p_handkarten_bot2 == NULL) {
                printf("Speicheranforderung fehlgeschlagen bei ziehe_karten\n");
            } else {
                for (int i = 0; i < anzahl; i++) {
                    p_handkarten_bot2[anzahl_karten_bot2] = Kartenstapel[oberste_stapel_karte];
                    Kartenstapel[oberste_stapel_karte].status = inDerHand;
                    oberste_stapel_karte++;
                    anzahl_karten_bot2++;
                }
            }
            break;
        case bot3:
            p_handkarten_bot3 = (Karte *) realloc(p_handkarten_bot3, (anzahl_karten_bot3 + anzahl) * sizeof(Karte));
            if (p_handkarten_bot3 == NULL) {
                printf("Speicheranforderung fehlgeschlagen bei ziehe_karten\n");
            } else {
                for (int i = 0; i < anzahl; i++) {
                    p_handkarten_bot3[anzahl_karten_bot3] = Kartenstapel[oberste_stapel_karte];
                    Kartenstapel[oberste_stapel_karte].status = inDerHand;
                    oberste_stapel_karte++;
                    anzahl_karten_bot3++;
                }
            }
            break;
        default:
            printf("Es gab ein Fehler beim Ziehen der Karten.\n");
            break;
    }
}

void entferne_karte(int wer, int index) {
    switch (wer) {
        case spieler:
            for (int i = index; i < anzahl_karten_spieler - 1; i++) {
                p_handkarten_spieler[i] = p_handkarten_spieler[i + 1];
            }
            if (anzahl_karten_spieler > 1) {
                p_handkarten_spieler = (Karte *) realloc(p_handkarten_spieler, (anzahl_karten_spieler - 1) * sizeof(Karte));
            }
            if (p_handkarten_spieler == NULL) {
                printf("Speicheranforderung fehlgeschlagen bei entferne_karten\n");
            }
            anzahl_karten_spieler--;
            break;
        case bot1:
            for (int i = index; i < anzahl_karten_bot1 - 1; i++) {
                p_handkarten_bot1[i] = p_handkarten_bot1[i + 1];
            }
            if (anzahl_karten_bot1 > 1) {
                p_handkarten_bot1 = (Karte *) realloc(p_handkarten_bot1, (anzahl_karten_bot1 - 1) * sizeof(Karte));
            }
            if (p_handkarten_bot1 == NULL) {
                printf("Speicheranforderung fehlgeschlagen bei entferne_karten\n");
            }
            anzahl_karten_bot1--;
            break;
        case bot2:
            for (int i = index; i < anzahl_karten_bot2 - 1; i++) {
                p_handkarten_bot2[i] = p_handkarten_bot2[i + 1];
            }
            if (anzahl_karten_bot2 > 1) {
                p_handkarten_bot2 = (Karte *) realloc(p_handkarten_bot2, (anzahl_karten_bot2 - 1) * sizeof(Karte));
            }
            if (p_handkarten_bot2 == NULL) {
                printf("Speicheranforderung fehlgeschlagen bei entferne_karten\n");
            }
            anzahl_karten_bot2--;
            break;
        case bot3:
            for (int i = index; i < anzahl_karten_bot3 - 1; i++) {
                p_handkarten_bot3[i] = p_handkarten_bot3[i + 1];
            }
            if (anzahl_karten_bot3 > 1) {
                p_handkarten_bot3 = (Karte *) realloc(p_handkarten_bot3, (anzahl_karten_bot3 - 1) * sizeof(Karte));
            }
            if (p_handkarten_bot3 == NULL) {
                printf("Speicheranforderung fehlgeschlagen bei entferne_karten\n");
            }
            anzahl_karten_bot3--;
            break;
        default:
            printf("Die Karte konnte nicht entfernt werden.\n");
            break;
    }
}


void spielroutine_spieler() {
    char erste_eingabe[12];
    char zweite_eingabe[18];
    int ist_karte_nummer = 0;
    int *moegliche_karten = calloc(1, sizeof(int));
    int anzahl_moegliche_karten = 0;
    int eingabe_erfolgreich = 0;
    zeige_handkarten_spieler();
    pause(2);
    suche_moegliche_karten(p_handkarten_spieler, anzahl_karten_spieler, moegliche_karten, &anzahl_moegliche_karten);
    if (anzahl_moegliche_karten > 0) {
        printf("Welche Karte willst du spielen?\n");
        do {
            scanf("%s %s", erste_eingabe, zweite_eingabe);
            printf("\n");
            int karten_funktion = gib_funktion(zweite_eingabe, &ist_karte_nummer);
            int zwischenspeicher = gib_farbe(erste_eingabe);
            for (int i = 0; i < anzahl_moegliche_karten; i++) {
                int karten_index = moegliche_karten[i];
                Karte k = p_handkarten_spieler[karten_index];
                if (k.farbe == zwischenspeicher) {
                    if (ist_karte_nummer == 0) {                //ist_karte eine funktion
                        if (k.typ == karten_funktion) {
                            eingabe_erfolgreich = 1;
                            spiele_karte(spieler, karten_index);
                        }
                    }
                    if (ist_karte_nummer == 1) {                //ist_karte eine zahl
                        if (k.nummer == karten_funktion) {
                            eingabe_erfolgreich = 1;
                            spiele_karte(spieler, karten_index);
                        }
                    }
                }
            }
            if (eingabe_erfolgreich == 0) {
                printf("Ich habe dich nicht verstanden, bitte Eingabe wiederholen.\n");
            }
        } while (eingabe_erfolgreich == 0);
    } else {
        if (zieh_counter > 0) {
            printf("Du musst %d Karten abheben\n", zieh_counter);
            pause(2);
            ziehe_karten(spieler, zieh_counter);
            zieh_counter = 0;
        } else {
            ziehe_karten(spieler, 1);
            printf("Du kannst nichts spielen, du ziehst eine Karte.\n\n");
            pause(2);
        }
        naechster_spieler(1);
    }
    free(moegliche_karten);
    //printf("Ende Spieler Zug DEBUG\n");
}

int gib_farbe(char *erste_eingabe) {
    if (strcmp(erste_eingabe, "blau") == 0) {
        return blau;
    }
    if (strcmp(erste_eingabe, "gruen") == 0) {
        return gruen;
    }
    if (strcmp(erste_eingabe, "rot") == 0) {
        return rot;
    }
    if (strcmp(erste_eingabe, "gelb") == 0) {
        return gelb;
    }
    if (strcmp(erste_eingabe, "schwarz") == 0) {
        return schwarz;
    } else {
        return 404;
    }
}

int gib_funktion(char *zweite_eingabe,
                 int *ist_karte_nummer) {            //zahl, plus2, plus4, aussetzen, richtungswechsel, farbwunsch
    if (strcmp(zweite_eingabe, "plus2") == 0) {
        *ist_karte_nummer = 0;
        return plus2;
    }
    if (strcmp(zweite_eingabe, "plus4") == 0) {
        *ist_karte_nummer = 0;
        return plus4;
    }
    if (strcmp(zweite_eingabe, "aussetzen") == 0) {
        *ist_karte_nummer = 0;
        return aussetzen;
    }
    if (strcmp(zweite_eingabe, "richtungswechsel") == 0) {
        *ist_karte_nummer = 0;
        return richtungswechsel;
    }
    if (strcmp(zweite_eingabe, "farbwunsch") == 0) {
        *ist_karte_nummer = 0;
        return farbwunsch;
    }
    int karten_zahl = atoi(zweite_eingabe);
    *ist_karte_nummer = 1;
    return karten_zahl;
}

void spielroutine_bot(int wer) {
    int *moegliche_karten = (int *) calloc(1, sizeof(int));
    if (moegliche_karten == NULL) {
        printf("Speicheranforderung fehlgeschlagen");
    }
    int anzahl_moegliche_karten = 0;
    switch (wer) {
        case bot1:
            printf("Soeren hat noch %d Karte(n).\n", anzahl_karten_bot1);  //Kartenzahl des Bots anzeigen lassen
            pause(2);
            anzahl_moegliche_karten = 0;
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
                    printf("Soeren muss %d Karten abheben.\n", zieh_counter);
                    ziehe_karten(bot1, zieh_counter);
                    zieh_counter = 0;
                } else {
                    ziehe_karten(bot1, 1);
                    printf("Soeren kann nicht legen, er hebt ab.\n\n");
                }
                naechster_spieler(1);
            }
            break;
        case bot2:
            printf("Brigitte hat noch %d Karte(n).\n", anzahl_karten_bot2);
            pause(2);
            anzahl_moegliche_karten = 0;
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
                    printf("Brigitte muss %d Karten abheben.\n", zieh_counter);
                    ziehe_karten(bot2, zieh_counter);
                    zieh_counter = 0;
                } else {
                    ziehe_karten(bot2, 1);
                    printf("Brigitte kann nicht legen, sie hebt ab.\n\n");
                }
                naechster_spieler(1);
            }
            break;
        case bot3:
            printf("Guenther hat noch %d Karte(n).\n", anzahl_karten_bot3);
            pause(2);
            anzahl_moegliche_karten = 0;
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
                    printf("Guenther muss %d Karten abheben.\n\n", zieh_counter);
                    ziehe_karten(bot3, zieh_counter);
                    zieh_counter = 0;
                } else {
                    ziehe_karten(bot3, 1);
                    printf("Guenther kann nicht legen, er hebt ab.\n\n");
                }
                naechster_spieler(1);
            }
            break;
    }
    free(moegliche_karten);
}

void suche_moegliche_karten(Karte *handkarten, int karten_anzahl, int *moegliche_karten, int *anzahl_moegliche_karten) {
    for (int i = 0; i < karten_anzahl; i++) {
        Karte g = handkarten[i];
        if (pruefe_karte(g) == 1) {
            *anzahl_moegliche_karten = *anzahl_moegliche_karten + 1;
            moegliche_karten = realloc(moegliche_karten, (*anzahl_moegliche_karten * sizeof(int)));
            if (moegliche_karten == NULL) {
                printf("fehler in der suche moeglich karten");
            }
            moegliche_karten[*anzahl_moegliche_karten - 1] = i;
        }
    }
}

int pruefe_karte(Karte pruef_karte) {
//  printf("Letzte Karte -> Typ: %d, Farbe: %d, Nummer: %d \n", letzte_karte.typ, letzte_karte.farbe, letzte_karte.nummer);
//  printf("Pruefkarte -> Typ: %d, Farbe: %d, Nummer: %d\n \n", pruef_karte.typ, pruef_karte.farbe, pruef_karte.nummer);
//	Testausgaben
    switch (letzte_karte.typ) {
        case zahl:
            if (letzte_karte.farbe == pruef_karte.farbe || letzte_karte.nummer == pruef_karte.nummer ||
                pruef_karte.farbe == schwarz) {
                return 1;
            }                //auf zahl geht gleiche zahl, gleiche farbe, schwarz
            return 0;
            break;
        case plus2:
            if (zieh_counter == 0) {    //wenn vorheriger Spieler schon abgehoben hat
                if (letzte_karte.farbe == pruef_karte.farbe || pruef_karte.farbe == schwarz ||
                    pruef_karte.typ == plus2) {
                    return 1;
                } else {                //wenn Spieler eine "scharfe" Plus2 bekommt
                    if (pruef_karte.typ == plus2 || pruef_karte.typ == plus4) {
                        return 1;
                    }
                }
            }                        //auf plus2 geht plus2 und schwarze plus4
            return 0;
            break;
        case plus4:
            if (zieh_counter == 0) {    //wenn vorheriger Spieler schon abgehoben hat
                if (pruef_karte.typ == plus4 || (pruef_karte.typ == plus2 && pruef_karte.farbe == wunschfarbe)) {
                    return 1;
                }                        //auf plus4 geht plus4 oder plus 2 in der richtigen farbe
            } else {                //wenn Spieler eine "scharfe" Plus4 bekommt
                if (pruef_karte.typ == plus2 || pruef_karte.typ == plus4) {
                    return 1;
                }
            }
            return 0;
            break;
        case aussetzen:
            if (pruef_karte.typ == aussetzen || letzte_karte.farbe == pruef_karte.farbe ||
                pruef_karte.farbe == schwarz) {
                return 1;
            }                        //auf aussetzen geht gleiche farbe oder aussetzen oder schwarz
            return 0;
            break;
        case richtungswechsel:
            if (pruef_karte.typ == richtungswechsel || letzte_karte.farbe == pruef_karte.farbe ||
                pruef_karte.farbe == schwarz) {
                return 1;
            }                        // auf richtungswechsel geht gleiche farbe oder richtungswechsel oder schwarz
            return 0;
            break;
        case farbwunsch:
            if (pruef_karte.farbe == wunschfarbe || pruef_karte.farbe == schwarz) {
                return 1;
            }                        // auf farbwunsch geht gewünschte farbe oder schwarz
            return 0;
            break;
        default:
            printf("Diesen Kartentypen gibt es leider nicht.\n");
            break;
    }
    return 0;
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
            printf("Soeren hat folgende Karte gelegt: %s %s %d \n\n",
                   karten_uebersetzung_farbe[p_handkarten_bot1[index].farbe],
                   karten_uebersetzung_typ[p_handkarten_bot1[index].typ], p_handkarten_bot1[index].nummer);
            entferne_karte(bot1, index);
            printf("Soeren hat noch %d Karte(n).\n\n", anzahl_karten_bot1);  //Kartenzahl des Bots anzeigen lassen
            break;
        case bot2:
            letzte_karte = p_handkarten_bot2[index];
            Kartenstapel[p_handkarten_bot2[index].index].status = abgelegt;
            switch (p_handkarten_bot2[index].typ) {
                case plus4:
                    zieh_counter = zieh_counter + 4;
                    break;
                case plus2:
                    zieh_counter = zieh_counter + 2;
                    break;
                case richtungswechsel:
                    aendere_spielrichtung();
                    break;
            }
            printf("Brigitte hat folgende Karte gelegt: %s %s %d \n\n",
                   karten_uebersetzung_farbe[p_handkarten_bot2[index].farbe],
                   karten_uebersetzung_typ[p_handkarten_bot2[index].typ], p_handkarten_bot2[index].nummer);
            entferne_karte(bot2, index);
            printf("Brigitte hat noch %d Karte(n).\n\n", anzahl_karten_bot2);
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
            printf("Guenther hat folgende Karte gelegt: %s %s %d \n\n",
                   karten_uebersetzung_farbe[p_handkarten_bot3[index].farbe],
                   karten_uebersetzung_typ[p_handkarten_bot3[index].typ], p_handkarten_bot3[index].nummer);
            entferne_karte(bot3, index);
            printf("Guenther hat noch %d Karte(n).\n\n", anzahl_karten_bot3);
            break;
        case spieler:
            letzte_karte = p_handkarten_spieler[index];
            Kartenstapel[p_handkarten_spieler[index].index].status = abgelegt;
            switch (p_handkarten_spieler[index].typ) {
                case farbwunsch:
                    wuensche_farbe_spieler();
                    break;
                case plus4:
                    wuensche_farbe_spieler();
                    zieh_counter += 4;
                    break;
                case plus2:
                    zieh_counter += 2;
                    break;
                case richtungswechsel:
                    aendere_spielrichtung();
                    break;
            }
            entferne_karte(spieler, index);
            break;
        default:
            printf("Spieler wurde nicht gefunden.\n");
            break;
    }
    if (letzte_karte.typ == aussetzen) {
        if (aktueller_spieler != spieler) {
            printf("%c muss wohl leider aussetzen.\n\n", aktueller_spieler);
        } else {
            printf("Du musst wohl leider aussetzen.\n\n");
        }
        naechster_spieler(2);
    } else {
        naechster_spieler(1);
    }
}

void wuensche_farbe(int farbe) {
    wunschfarbe = farbe;
    printf("Die Farbe %d wurde gewuenscht.\n", wunschfarbe);
}

void wuensche_farbe_spieler() {
    char eingegebene_wunschfarbe;
    int gewuentschte_farbe;
    printf("Bitte eine Farbe eingeben.\n");
    do {
        scanf("%s", &eingegebene_wunschfarbe);
        gewuentschte_farbe = gib_farbe(&eingegebene_wunschfarbe);
        wuensche_farbe(gewuentschte_farbe);
    } while (gewuentschte_farbe == 404 || gewuentschte_farbe == schwarz);
}

void aendere_spielrichtung() {
    if (spiel_richtung == rechts) {
        spiel_richtung = links;
    } else {
        spiel_richtung = rechts;
    }
}

void naechster_spieler(int schritte) {
    if (spiel_richtung == rechts) {
        aktueller_spieler = (aktueller_spieler + schritte) % 4;
    } else {
        aktueller_spieler = (4 + aktueller_spieler - schritte) % 4;
    }
}





