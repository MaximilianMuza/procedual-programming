#include <stdio.h>
#include <math.h>

int main() {
	
	float a, b, c, num, x, sum, sum_old;
	unsigned int k, n;

	k = 0;
	a = -1.0;
	c = sum = x = 0.0;
	sum_old = 1.0;

	printf("Bitte gebe einen Wert für x ein: ");
	// Erhalte eingegebenen Wert von N
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
				c = num - n;
			
			} else {
			
				b *= x;
				c *= num - n;			
			}
		
		}

		sum_old = sum;
		sum += (a * b) / c;

		printf("k: %d - Annäherung: %.10f\n", k, sum);

	}

	printf("\nAnnäherung: %.10f | sin(%.3f)-Wert: %.10f\n", sum, x, sin(x));

	return 0;
}
