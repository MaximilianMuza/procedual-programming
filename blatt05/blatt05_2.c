#include <stdio.h>
#include <stdint.h>

int main() {
	
	unsigned int i, v, num;
	i = v = num = 0;
	printf("Gebe den Wert, den Spaltenindex und Reihenindex an: ");
	scanf("%d,%d,%d", &num, &i, &v);
	printf("%d,%d,%d", num, i, v);
	
	return 0;
}
