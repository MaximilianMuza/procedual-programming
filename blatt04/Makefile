#
# Variablen helfen in Makefiles copy&paste zu verringern und die "Rezepte"
# uebersichtlicher zu gestalten.
#

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -lm

# Rezept wird mit `make blatt02_1.exe` aufgerufen, Windows-Nutzer muessen vor
# `./blatt02_1.exe` ggf. das `./` entfernen.

blatt04_1.exe: blatt04_1.c
	$(CC) $(CFLAGS) -o blatt04_1.exe blatt04_1.c
	./blatt04_1.exe

blatt04_2.exe: blatt04_2.c
	$(CC) $(CFLAGS) -o blatt04_2.exe blatt04_2.c
	./blatt04_2.exe

blatt04_3.exe: blatt04_3.c
	$(CC) $(CFLAGS) -o blatt04_3.exe blatt04_3.c
	./blatt04_3.exe