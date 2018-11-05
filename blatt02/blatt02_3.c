
#include <stdio.h>
#include <stdint.h>

int main() {
	
	// Variablen werden definiert und anschließend Werte zugewiesen
	int N, H, B, h, b, dH, dB;
	N = 3;
	H = B = 1;
	// b = c - 1;
	// a = b - 1;

	printf("Programm zur Ausgabe einer Zahlen Raute\n\n");

	// Der Wert von H iteriert bis er der Anzahl der vertikalen Kästchen entspricht
	while(H < 2*N) {
		
		dH = N - H; 
		if(dH < 0) {
			dH = -dH;
		}
		h = N - dH;

		// Der Wert von B iteriert bis er der Anzahl der horizontalen Kästchen entspricht
		while(B < 2*N) {

			dB = N - B;
			if(dB < 0) {
				dB = -dB;
			}
			b = h - dB;

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
