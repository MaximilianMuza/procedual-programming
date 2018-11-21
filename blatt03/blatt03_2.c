#include <stdio.h>
#include <stdint.h>

int main() {

	// Initialisiere Float Variablen
	float approx = 1.0, t = 1.0, x = 1.0, approx_old = 0.0;
	// Setze Integer i null
	int i = 0;

	// Iteriere solange die Summe nicht der hervorigen 
	while(approx != approx_old) {
		i++; /* Erhöhe Index i jede Schleife um 1 */
		t = t * x / i; /* Rechnung entspricht (1/i!) */
		approx_old = approx; /* Setze gleich*/
		approx += t; /* Erhöhe die Annäherung um den Wert t */
		printf("\ni = %d, t = %f, approx_old = %f, approx = %f, \n",i,t,approx_old,approx);
	}

	// Gebe maschinengenau Annäherung an e aus
	printf("\nMaschinengenaue Näherung an e: %f\n", approx);

	return 0;
}
