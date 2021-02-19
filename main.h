#ifndef main_never_used
#define main_never_used

int main();
int spiel_schleife();

enum {spieler, bot1, bot2, bot3};
enum richtung {links, rechts};
enum {start, spiel, spielende};

int spiel_richtung;
int spieler_reihenfolge[4];
int aktueller_spieler;
int bot;

void pause();
void init_spiel();
void pause();

#endif
