#include <stdio.h>
#include <stdint.h>

int main() {
	
	float epsilon = 1.0;
	int i = 1;

	do {

		epsilon = 0.5 * epsilon;
		printf("%d: %.50f\n", i, epsilon);
		i++;

	} while(1 + 0.5 * epsilon > 1);

	return 0;
}