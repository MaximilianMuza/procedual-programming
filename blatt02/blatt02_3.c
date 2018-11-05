
#include <stdio.h>
#include <stdint.h>

int main() {
	
	// Variablen werden definiert und anschließend Werte zugewiesen
	int N, H, B, h, b, dH, dB;
	H = B = 1;

	// Gebe Text aus und frage nach Wert für N
	printf("Bitte gebe eine Zahl zwischen 0 und 10 ein: ");
	// Erhalte eingegebenen Wert von N
    scanf("%d", &N);

	printf("Programm zur Ausgabe einer Zahlen Raute\n\n");

	// Der Wert von H iteriert bis er der Anzahl der vertikalen Kästchen entspricht
	while(H < 2*N) {
		
		// Berechnen der Differenz von N und H
		dH = N - H; 

		// Nehme den Betrag von dH
		if(dH < 0) {
			
			dH = -dH;
		
		}

		// Berechnen der Differenz
		h = N - dH;

		// Der Wert von B iteriert bis er der Anzahl der horizontalen Kästchen entspricht
		while(B < 2*N) {

			// Berechnen der Differenz von N und B 
			dB = N - B;
			
			// Nehme den Betrag von dB
			if(dB < 0) {
			
				dB = -dB;
			
			}
			
			// Berechne Wert des Kästchens in Reihe H und Spalte B
			b = h - dB;

			// Ausgeben der Werte
			// Ausnahme für Werte kleiner null 
			if(b <= 0) {
			
				printf(" ");
			
			} else {
			
				printf("%d", b);
			
			}

			// Erhöhen von B um eins und Wechseln ins nächste Kästchen der Reihe
			B++;

		}

		printf("\n");

		// Die Variable H wird um eins erhöht, um somit die nächste Reihe zu betrachten
		H++;

		// Der Wert B wird für die nächste Reihe auf 1 zurückgesetzt 
		B = 1;

	}

	// Ausgeben einer Leerzeile
	printf("\n");

  	return 0;
}
