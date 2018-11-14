#include <stdio.h>
#include <stdint.h>

int main() {
	
	unsigned int  a = 200, b = 3, product, remainder;
	int i = 1;
	
	// do {

	// 	product = b * i;
	// 	i++;

	// } while(product <= a);

	// remainder = a - (product - b);

	// do {

	// 	remainder = a % b;
	// 	a = b;
	// 	b = remainder;

	// } while(b != 0);

	printf("%d\n", remainder);
	return 0;
}




// #include <stdio.h>
// #include <stdint.h>

// int main() {
	
// 	unsigned int  a = 200, b = 3, product, remainder;
// 	int i = 1;

// 	do {
// 		do {
// 			product = b * i;
// 			i++;
// 		} while(product <= a);
		
// 		remainder = a - (product - b);
// 		a = b;
// 		b = remainder;

// 	} while(b != 0);

// 	printf("%d\n", a);
// 	return 0;
// }