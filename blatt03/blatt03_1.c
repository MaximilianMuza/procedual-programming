
#include <stdio.h>
#include <stdint.h>

int main() {
	
	float y = 1.0, t = 1.0, x = 1.0;
	int i = 0;
	while(t > 1e-7) {
		i = i + 1;
		t = t * x / i;
		y = y + t;
	}
	printf("e ist: %f", y);
	return 0;
}