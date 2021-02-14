#include <stdio.h>
#include "kartendeck.h"
#include "handkarten.h"

int main() {
    mische_karten();
    hole_handkarten_speicher();
    teile_karten_aus();
    zeige_handkarten_spieler();
    return 0;
}
