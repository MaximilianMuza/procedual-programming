
#include <stdio.h>
#include <stdint.h>

int main() {
	
	// Variablen werden definiert und anschließend Werte zugewiesen
	uint8_t N,H,B,a,b,c;
	N = 3;
	H = B = 1;
	c = 1;
	a = b = 0;

	printf("Programm zur Ausgabe einer Zahlen Raute\n\n");

	// Der Wert von H iteriert bis er der Anzahl der vertikalen Kästchen entspricht
	while(H < 2*N) {

		// Für den Fall dass H den Wert 2 oder 4 hat, sollen die Werte aus den entsprechenden Reihen zugewiesen werden
		if(H == 2 || H == 4) {

			a = 0;
			b = 1;
			c = 2;
		// Das gleiche wird für die dritte Reihe gemacht
		} else if(H == 3) {

			a = a + 1;
			b = b + 1;
			c = c + 1;

		// Und die fünfte
		} else if(H == 5) {

			a = b = 0;
			c = 1;

		}
		
		// Ausgeben der Werte in horizontaler Richtung
		printf("%d %d %d %d %d\n",a,b,c,b,a);

		// Die Variable H wird um eins erhöht, um somit die nächste Reihe zu betrachten
		H = H + 1;

	}

	printf("\n");

  	return 0;
}
