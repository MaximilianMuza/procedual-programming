
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

		// 
		if(H == (N - 2) || H == (N + 2)) {

			n = N - 2;

		} else if(H == (N - 1) || H == (N + 1)) {

			n = N - 1;

		} else if(H == N) {

			n = N;

		}
		
		// Der Wert von B iteriert bis er der Anzahl der horizontalen Kästchen entspricht
		while(B < 2*N) {

			if (B == (N - 2) || B == (N + 2)) {

				r = n - 2;

				if(r < 0) {

					r = 0;

				}

			} else if(B == (N - 1) || B == (N + 1)) {

				r = n - 1;
		
			} else if(B == N) {

				r = n;
			}

			printf("%d", r);

			if(B == (N + 2)) {

				printf("\n");
			
			}

			B = B + 1;

		}
		// Ausgeben der Werte in horizontaler Richtung
		// printf("%d %d %d %d %d\n",a,b,c,b,a);

		// Die Variable H wird um eins erhöht, um somit die nächste Reihe zu betrachten
		H = H + 1;

		// Der Wert B wird auf 1 zurückgesetzt
		B = 1;

	}

	printf("\n");

  	return 0;
}
