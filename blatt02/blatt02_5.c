
#include <stdio.h>
#include <stdint.h>

int main() {

	float x, y;
	x = -5;

	printf("Programm zur Ausgabe der Werte einer Normalparabel\n");
	printf("x-Wert  |  y-Wert\n");

	while(x <= 5) {

		y = x*x;

		printf("%f  |  %f\n", x, y);

		x = x + 0.125;

	}

   	return 0;

}
