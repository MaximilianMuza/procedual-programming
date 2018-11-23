#include <stdio.h>

int Array[9][9] = {0};

int outputSodoku(int num, int i, int v, int state) {
	Array[i-1][v-1] = num;

	printf("\nSODOKU\n");
	printf("    1 2 3   4 5 6   7 8 9\n");
	printf("  +-------+-------+-------+\n");
	for (i = 0; i < 9; i++) {
		printf("%d | ", i+1);
		for (v = 0; v < 9; v++) {
			if(Array[i][v] == 0) state = 0; 
			printf("%d ", Array[i][v]);
			if((v+1)%3==0) {
				printf("| ");
			}
		}
		printf("\n");
		if((i+1)%3 == 0) {
		    printf("  +-------+-------+-------+\n");
		}
	}
	return state;
}

int checkSodoku() {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			if(Array[x][y] != 0) {
				for (int z = 0; z < 9; z++) {
					if(Array[x][y] == Array[x][z] && y != z) {
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int main() {
	
	int i, v, num, state;
	num = state = 0;
	i = v = 1;

	state = outputSodoku(num, i, v, state);

	do {

		printf("Gebe den Wert, den Reihenindex und Spaltenindex an: ");
		scanf("%d,%d,%d", &num, &i, &v);
		while(num > 9 || num < 0 || i > 9 || i < 1 || v > 9 || v < 1) {
			printf("Du kannst nur Werte zwischen 1 und 9 wählen. Versuche erneut: ");
			scanf("%d,%d,%d", &num, &i, &v);
		}
		state = outputSodoku(num, i, v, state);
		while(checkSodoku() == 0) {
			printf("Du hast einen Fehler gemacht. Versuche erneut: ");
			scanf("%d,%d,%d", &num, &i, &v);
		}	

	} while(state == 0);

	
	return 0;
}
