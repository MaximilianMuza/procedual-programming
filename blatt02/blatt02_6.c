
#include <stdio.h>
#include <stdint.h>

int main() {

	int a, b, c, low, mid, high;
	a = 10;
	b = -8;
	c = 55;

	printf("Programm zur aufsteigenden Sortierung von drei Variablen\n");

	if(a < b) {

		low = a;
		high = b;

	} else {

		low = b;
		high = a;

	}
	if(low > c) {

		mid = low;
		low = c;

	} else {

		if(c > high) {

			mid = high;
			high = c;

		} else {

			c = mid;

		}
	}

	printf("%d\n", low);
	printf("%d\n", mid);
	printf("%d\n", high);

   	return 0;

}
