#include <stdio.h>
#include <stdint.h>

int main() {
	
	unsigned int a = 3528, b = 3780, orig_a, orig_b, remainder;
	
	orig_a = a;
	orig_b = b;

	do {

		remainder = a % b;
		a = b;
		b = remainder;

	} while(b != 0);

	printf("\nDer ggT von %d und %d lautet: %d\n\n", orig_a, orig_b, a);

	return 0;
}