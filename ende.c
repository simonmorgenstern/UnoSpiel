#include "ende.h"

//SL
int spiel_ende_benachrichtigung(){
	char spiel_fortsetzen;
	int bot = 1;				//Variable wer gewonnen hat, kann/muss noch angepasst werden
	if (bot == 1){
		srand(time(NULL));
		int r = rand() % 4;     // Zufällige Zahl zwischen 0 und 3 (4 Möglichkeiten)
		switch(r){
			case 0:
				printf("Mal verliert man, mal gewinnt ein anderer ;-)\n");
				break;
			case 1:
				printf("Zweiter zu sein bedeutet Erster der Verlierer zu sein.\n");
				break;
			case 2:
				printf("Man ist niemals ein Verlierer - bis man aufgibt.\n");
				break;
			case 3:
				printf("Aus Niederlagen lernt man leicht. Schwieriger ist es, aus Siegen zu lernen.\n");
				break;
			default:
				printf("Viel Glück beim nächsten Mal.\n");
		}
	}
	else{
		printf("Glückwunsch, du hast gewonnen ^-^ \n");
	}
	pause(3);
	printf("Möchtest du noch einmal spielen?\nWenn ja bestaetige mit y oder n.\nOder willst du wieder ins Menue? -> m\n");
	spiel_fortsetzen = getchar();
	while(getchar() != '\n');
	switch(spiel_fortsetzen){
		case 'y':
			return 1;					//korrigiert, war spiel()
			break;
		case 'n':
			printf("Schade, bis zum naechsten Mal.\n");
			break;
		case 'm':
			menue();
	}
	return 0;
}
