#include <stdio.h>
#include <stdint.h>

int main() {
	
	unsigned int  a = 200, b = 3, product, remainder;
	int i = 1;

	do {
		do {
			product = b * i;
			i++;
		} while(product <= a);

		remainder = a - (product - b);
		a = b;
		b = remainder;

	} while(b != 0);

	printf("%d\n", a);
	return 0;
}


// 		do {
// 			product = b * i;
// 			i++;
// 		} while(product <= a);
		
// 		remainder = a - (product - b);
