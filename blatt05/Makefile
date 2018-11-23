#
# Variablen helfen in Makefiles copy&paste zu verringern und die "Rezepte"
# uebersichtlicher zu gestalten.
#

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -lm

# Rezept wird mit `make blatt02_1.exe` aufgerufen, Windows-Nutzer muessen vor
# `./blatt02_1.exe` ggf. das `./` entfernen.

blatt05_1.exe: blatt05_1.c
	$(CC) $(CFLAGS) -o blatt05_1.exe blatt05_1.c
	./blatt05_1.exe

blatt05_2.exe: blatt05_2.c
	$(CC) $(CFLAGS) -o blatt05_2.exe blatt05_2.c
	./blatt05_2.exe