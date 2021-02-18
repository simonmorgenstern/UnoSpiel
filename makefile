CC = gcc -Wall
Objektdateien = main.o handkarten.o kartendeck.o menue.o ende.o
Programm = main.exe

$(Programm): $(Objektdateien)
	$(CC) -o $@ $^

# explizite Regel definiert das Kommando
$(Objektdateien):
	$(CC) -c $<

# implizite Regeln definieren die Abhängigkeiten
main.o: main.c kartendeck.h handkarten.h menue.h ende.h
menue.o: menue.c menue.h
kartendeck.o: kartendeck.c kartendeck.h
handkarten.o: handkarten.c handkarten.h kartendeck.h main.h
ende.o: ende.c ende.h menue.h

all: clean $(Programm) run
clean:
	rm $(Objektdateien) $(Programm) -f

run:
	./$(Programm)
