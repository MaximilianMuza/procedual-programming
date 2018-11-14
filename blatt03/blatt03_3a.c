#include <stdio.h>
#include <stdint.h>

int main() {
	
	unsigned int a = 3528, b = 3780, diff_abs, orig_a, orig_b;
	
	orig_a = a;
	orig_b = b;

	// Iteriere solange beide Werte a, b ungleich Null sind
	// Sobald einer Null ist breche Schleife ab
	while(a != 0 && b != 0) {
		// für den Fall a ist kleiner b
		if(a < b) {
			diff_abs = b - a; /* berechne Differenz (absolut) */
			b = diff_abs; /* setze größeren Wert gleich der Differenz */
		// für den Fall a ist größer gleich b
		} else {
			diff_abs = a - b; /* berechne Differenz (absolut) */
			a = diff_abs; /* setze größeren Wert gleich der Differenz */
		}
	}

	if(a == 0) {
		// Gebe den Wert ungleich null aus
		printf("\nDer ggT von %d und %d lautet: %d\n\n", orig_a, orig_b, b);
	} else {
		// Gebe den Wert ungleich null aus
		printf("\nDer ggT von %d und %d lautet: %d\n\n", orig_a, orig_b, a);
	}

	return 0;
}