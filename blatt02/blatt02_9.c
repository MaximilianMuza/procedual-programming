
#include <stdio.h>
#include <stdint.h>

int main() {

	int8_t num_1, num_2, sum, wrap_state;
	num_1 = 20;
	num_2 = 0;
	wrap_state = 0;

	printf("Programm zur Ausgabe von Zahlen die addiert mit 20 nicht zum wrap-around führen\n");

	while(!wrap_state) {

		sum = num_1 + num_2;
		printf("%d\n", sum);

		num_2++;
		
	}

   	return 0;

}
