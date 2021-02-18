#ifndef main_never_used
#define main_never_used

int main();

enum {spieler, bot1, bot2, bot3};
enum richtung {links, rechts};
enum {start, spiel, spielende};

int spiel_richtung;
int spieler_reihenfolge[4];
int aktueller_spieler;


void init_spiel();
void spiel_schleife();
void pause();

#endif
