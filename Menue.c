#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void fehlermeldung();
void menue();
void regeln_einlesen();
void spiel();
void spielkommandos();
//SL
int programmstart(){
	char spielstart;
	printf("Hallo, willst du UNO spielen?\n");
	printf("Bestaetige mit y oder verneine mit n\n");
	do{
		spielstart = getchar();
		while(getchar() != '\n');
		switch(spielstart){
			case 'y':
				//printf("Super, dann los =)\n");
				menue();
				break;
			case 'n':
				printf("Oh, schade, bis bald. =)\n");
				return 0;
				break;
			default:
				fehlermeldung();
				break;
		}
	} while (1);
}
//SL
void fehlermeldung(){
	printf("Es tut mir Leid ich habe dich nicht verstanden :-/\nBitte Eingabe wiederholen.\n");
}
//SL
void menue(){
	int menuepunkt = 0;
	printf("------Menue------\n");
	printf("1. Spiel starten\n");
	printf("2. Regeln\n");
	printf("3. Spielekommandos\n");
	printf("4. Beenden\n\n");
	do {
		menuepunkt = getchar();
		while(getchar() != '\n');			//lehrt Tastaturpuffer
		switch (menuepunkt){
			case '1':
				printf("Der Gamemaster mischt die Karten, einen Moment.\n");
				spiel();
				break;
			case '2':
				regeln_einlesen();
				printf("\n\nZum Menue mit Enter\n\n");
				while(getchar() != '\n');
				menue();
				break;
			case '3':
				spielkommandos();
				printf("\n\nZum Menue mit Enter\n\n");
				while(getchar() != '\n');
				menue();
				break;
			case '4':
				printf("Oh, schade, bis bald. =)\n");
				break;
			default:
				fehlermeldung();
				break;
		} 
	} while(1);
}
//SL
void regeln_einlesen(){
	FILE *fp;
	char *fname = "Regeln.txt";
	char output;
	if ((fp = fopen(fname, "r"))== NULL){
		fprintf(stderr, "Fehler beim Oeffnen, bitte Spiel neu starten\n");
	}
	else{
		printf("Regeln:\n");
	}
	while ((fscanf(fp, "%c", &output)) != EOF){
		printf("%c", output);
	}
	fclose(fp);
}
//SL
void spiel(){
	printf("Hier startet spaeter das Spiel\n");
}
//SL
void spielkommandos(){
	FILE *fp;
	char *fname = "Spielkommandos.txt";
	char output;
	if ((fp = fopen(fname, "r"))== NULL){
		fprintf(stderr, "Fehler beim Oeffnen, bitte Spiel neu starten\n");
	}
	else{
		printf("Spielkommandos:\n\n");
	}
	while ((fscanf(fp, "%c", &output)) != EOF){
		printf("%c", output);
	}
	fclose(fp);
}

