
#include <stdio.h>
#include <stdint.h>

int main() {
	
	// Variablen werden definiert und anschließend Werte zugewiesen
	int N, H, B, n, r;
	N = 3;
	H = B = 1;
	// b = c - 1;
	// a = b - 1;

	printf("Programm zur Ausgabe einer Zahlen Raute\n\n");

	// Der Wert von H iteriert bis er der Anzahl der vertikalen Kästchen entspricht
	while(H < 2*N) {

		// Initialisierung von n für spätere Rechenoperationen 
		// Für die erste und letzte Kästchen-Reihe gilt 
		if(H == (N - 2) || H == (N + 2)) {

			n = N - 2;

		// Für die zweite und vorletzte Kästchen-Reihe gilt
		} else if(H == (N - 1) || H == (N + 1)) {

			n = N - 1;

		// Für die mittlere Kästchen-Reihe gilt
		} else if(H == N) {

			n = N;

		}
		
		// Der Wert von B iteriert bis er der Anzahl der horizontalen Kästchen entspricht
		while(B < 2*N) {

			// Für das erste und letzte Kästchen der Reihe H ist der Wert wie folgt
			if (B == (N - 2) || B == (N + 2)) {

				r = n - 2;

				if(r < 0) {

					r = 0;

				}

			// Für das zweite und vorletzte Kästchen der Reihe H ist der Wert wie folgt
			} else if(B == (N - 1) || B == (N + 1)) {

				r = n - 1;
		
			// Für das mittlere Kästchen der Reihe H ist der Wert wie folgt 
			} else if(B == N) {

				r = n;
			}

			// Ausgeben des Wertes von r in dem Kästchen bestimmt durch H und B
			printf("%d", r);

			// Setzten eines Linienbruchs (Breaks) wenn Ende der Reihe erreicht ist
			if(B == (N + 2)) {

				printf("\n");
			
			}

			// Erhöhen von B um eins und Wechseln ins nächste Kästchen der Reihe
			B = B + 1;

		}

		// Die Variable H wird um eins erhöht, um somit die nächste Reihe zu betrachten
		H = H + 1;

		// Der Wert B wird für die nächste Reihe auf 1 zurückgesetzt 
		B = 1;

	}

	// Ausgeben einer Leerzeile
	printf("\n");

  	return 0;
}
