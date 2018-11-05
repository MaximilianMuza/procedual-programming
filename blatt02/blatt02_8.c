
#include <stdio.h>
#include <stdint.h>

int main() {

	int num = 1;
	printf("Programm zur Ausgabe von Zahlen, die durch drei teilbar sind.");

	while(num <= 100) {

		if(num%3 == 0) {

			printf("%d\n", num);

		}

		num++;
	}

   	return 0;

}
