
#include <stdio.h>
#include <stdint.h>

int main() {

	int16_t num_1, num_2;
	num_1 = 10000;

	printf("Programm zur Ausgabe von Zahlen die addiert mit 20 nicht zum wrap-around führen\n");

	for(num_2 = 1; num_2 <= (32767 - num_1); num_2++) {

		printf("%d\n", num_2);

	}

   	return 0;

}
