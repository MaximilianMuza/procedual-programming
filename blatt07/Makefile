#
# Variablen helfen in Makefiles copy&paste zu verringern und die "Rezepte"
# uebersichtlicher zu gestalten.
#

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -lm

# Rezept wird mit `make blatt02_1.exe` aufgerufen, Windows-Nutzer muessen vor
# `./blatt02_1.exe` ggf. das `./` entfernen.

blatt07_1.exe: blatt07_1.c
	$(CC) $(CFLAGS) -o blatt07_1.exe blatt07_1.c
	./blatt07_1.exe

blatt07_2.exe: blatt07_2.c
	$(CC) $(CFLAGS) -o blatt07_2.exe blatt07_2.c
	./blatt07_2.exe
