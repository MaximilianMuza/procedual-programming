#
# Variablen helfen in Makefiles copy&paste zu verringern und die "Rezepte"
# uebersichtlicher zu gestalten.
#

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -lm

# Rezept wird mit `make blatt02_1.exe` aufgerufen, Windows-Nutzer muessen vor
# `./blatt02_1.exe` ggf. das `./` entfernen.

main.exe: main.c
	$(CC) $(CFLAGS) -o main.exe main.c
	./main.exe
