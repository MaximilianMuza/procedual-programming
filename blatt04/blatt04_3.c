#include <stdio.h>
#include <math.h>

int main() {
	
	float a, b, num, x, sum, sum_old;
	int k;

	k = 0;
	x = sum = 0.0;	
	a = -1.0;
	sum_old = 1.0;

	printf("Bitte gebe einen Wert zwischen 0 und 2 für x ein: ");
	// Erhalte eingegebenen Wert von N
    scanf("%f", &x);

	for(k = 1; sum != sum_old; k++) {

		num = k + 1;
		a *= -1.0; 

		if(k == 1) {
		
			b = (x - 1);
		
		} else {
		
			b *= (x - 1);

		}

		sum_old = sum;
		sum += (a * b) / k;

		printf("k: %d - sum: %.10f\n", k, sum);

	}

	printf("\nAnnäherung: %.10f | log(%.3f)-Wert: %.10f\n", sum, x, log(x));

	return 0;
}
