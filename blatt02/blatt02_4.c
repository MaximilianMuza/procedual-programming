
#include <stdio.h>
#include <stdint.h>

int main() {

	int celsius_wert, kelvin_wert;

	kelvin_wert = 0;

	printf("Programm zur Umrechung von Celsius zu Kelvin\n");
	printf("Kelvin-Wert  |  Celsius-Wert\n");

	while(kelvin_wert <= 550) {

		celsius_wert = kelvin_wert - 273;
		printf("%dK  |  %d°C\n", kelvin_wert, celsius_wert);

		kelvin_wert++;

	}

   	return 0;

}
