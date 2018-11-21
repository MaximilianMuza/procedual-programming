#include <stdio.h>
#include <math.h>

int main() {
	
	float a, b, c, num, x, sum, sum_old;
	unsigned k, n;

	k = 0;
	x = 0.0;	
	a = -1.0;
	c = sum = 0.0;
	sum_old = 1.0;

	printf("Bitte gebe einen Wert zwischen -1 und 1 für x ein: ");
	// Erhalte eingegebenen Wert von x
    scanf("%f", &x);

	for(k = 0; sum != sum_old; k++) {

		num = 2 * k + 1;
		c = 0.0;

		if(k == 0) {
			
			a = 1.0;
		
		} else if (k == 1) {
		
			a = -1.0;
		
		} else {
		
			a *= -1.0; 
		
		}

		for(n = 0; n < num; n++) {

			if(n == 0) {
			
				b = x;
			
			} else {
			
				b *= x;
			}
		
		}

		c = num;
		sum_old = sum;
		sum += (a * b) / c;

		printf("k: %d | Annäherung: %.10f\n", k, sum);

	}

	printf("\nAnnäherung: %.10f | arctan(%.3f)-Wert: %.10f\n", sum, x, atan(x));

	return 0;
}
