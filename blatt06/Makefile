#
# Variablen helfen in Makefiles copy&paste zu verringern und die "Rezepte"
# uebersichtlicher zu gestalten.
#

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -lm

# Rezept wird mit `make blatt02_1.exe` aufgerufen, Windows-Nutzer muessen vor
# `./blatt02_1.exe` ggf. das `./` entfernen.

blatt06_1.exe: blatt06_1.c
	$(CC) $(CFLAGS) -o blatt06_1.exe blatt06_1.c
	./blatt06_1.exe
