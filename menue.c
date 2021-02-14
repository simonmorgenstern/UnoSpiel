#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void fehlermeldung();
int menue();
void regeln_einlesen();
void spielkommandos();
//SL
int spielstart();
//SL
void fehlermeldung(){
	printf("Es tut mir Leid ich habe dich nicht verstanden :-/\nBitte Eingabe wiederholen.\n");
}
// SL
int spielstart() {
    char spielstart;
    printf("Hallo, willst du UNO spielen?\n");
    printf("Bestaetige mit y oder verneine mit n\n");
    do{
        spielstart = getchar();
        while(getchar() != '\n');
        switch(spielstart){
            case 'y':
                //printf("Super, dann los =)\n");
                return menue();
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
int menue(){
	int menuepunkt = 0;
	printf("------Menue------\n");
	printf("1. Spiel starten\n");
	printf("2. Regeln\n");
	printf("3. Spielekommandos\n");
	printf("4. Beenden\n\n");
	do {
		menuepunkt = getchar();
		while(getchar() != '\n');			//lehrt Tastaturpuffer
		//scanf("%d", &menuepunkt);
		switch (menuepunkt){
			case '1':
				printf("Der Gamemaster mischt die Karten, einen Moment.\n");
				return 1;
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
				return 0;
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
		fprintf(stderr, "Fehler beim Oeffnen\n");
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
void spielkommandos(){
	FILE *fp;
	char *fname = "Spielkommandos.txt";
	char output;
	if ((fp = fopen(fname, "r"))== NULL){
		fprintf(stderr, "Fehler beim Oeffnen\n");
	}
	else{
		printf("Spielkommandos:\n\n");
	}
	while ((fscanf(fp, "%c", &output)) != EOF){
		printf("%c", output);
	}
	fclose(fp);
}

