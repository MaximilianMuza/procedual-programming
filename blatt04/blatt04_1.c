#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
	
	float a, b, c, num, x, sum;
	int k, n;

	k = 0;
	x = 0.0;	
	a = -1.0;
	c = sum = 0.0;

	printf("Bitte gebe einen Wert für x ein: ");
	// Erhalte eingegebenen Wert von N
    scanf("%f", &x);

	for(k = 0; k <= 20; k++) {

		num = 2 * k + 1;
		b = x;
		c = 0.0;

		if(k == 0) {
			
			a = 1;
		
		} else if (k == 1) {
		
			a = -1.0;
		
		} else {
		
			a = (a) * (-1.0); 
		
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

		sum += (a * b) / c;

		printf("a: %f - b: %f - c: %f - sum: %f\n", a,b,c, sum);

	}

	return 0;
}
