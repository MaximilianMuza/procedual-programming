#include <stdio.h>
#include <stdint.h>

int main() {
	
	unsigned int  a = 3528, b = 3780, product, remainder;
	int i = 1;

	do {
		do {
			product = b * i;
			i++;
		} while(product <= a);

		remainder = a - (product - b);
		a = b;
		b = remainder;

		i = 1;
		product = 0;

	} while(b != 0);

	printf("%d\n", a);

	return 0;
}


// 		do {
// 			product = b * i;
// 			i++;
// 		} while(product <= a);
		
// 		remainder = a - (product - b);
