
#include <stdio.h>
#include <stdint.h>

int main() {

	int N, n, r;
	N = 6;
	n = r = 1;

	while(n <= N) {

		while(r <= (N - (n - 1))) {

			printf("*");
			r++;

		}

		printf("\n");
		r = 1;
		n++;

	}

   	return 0;

}
