#include <stdio.h>

int Array[9][9] = {0};

int makeSodoku() {
	Array[0][2] = 7;
	Array[0][6] = 3;
	Array[0][8] = 2;
	Array[1][0] = 2;
	Array[1][5] = 5;
	Array[1][7] = 1;
	Array[2][3] = 8;
	Array[2][5] = 1;
	Array[2][6] = 4;
	Array[3][1] = 1;
	Array[3][4] = 9;
	Array[3][5] = 6;
	Array[3][8] = 8;
	Array[4][1] = 7;
	Array[4][2] = 6;
	Array[4][7] = 4;
	Array[4][8] = 9;
	Array[6][3] = 1;
	Array[6][5] = 3;
	Array[7][0] = 8;
	Array[7][2] = 1;
	Array[7][4] = 6;
	Array[8][3] = 7;
	Array[8][7] = 6;
	Array[8][8] = 3;
	return 0;
}

int outputSodoku(int i, int v, int state) {
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

int checkSodoku(int num, int i, int v) {
	i -= 1;
	v -= 1;
	for (int r = 0; r < 9; r++) { // Überprüfe ob alle Werte in der Reihe zu dem Wert unterschiedlich sind 
		if(num == Array[i][r] && v != r) {
			return 0;
		}
	}
	for (int s = 0; s < 9; s++) { // Überprüfe ob alle Werte in der Spalte zu dem Wert unterschiedlich sind 
		if(num == Array[s][v] && i != s) {
			return 0;
		}
	}
	int x_field, y_field;	
	x_field = (i/3)*3;
	y_field = (v/3)*3;

	for (int x = x_field; x < x_field + 3; x++) { // Überprüfe ob alle Werte im Kästchen zu dem Wert unterschiedlich sind 
		for (int y = y_field; y < y_field + 3; y++) {
			if(num == Array[x][y] && i != x && v != y) {
				return 0;
			}
		}
	}

	Array[i][v] = num;
	return 1;
}

int main() {
	
	int i, v, num, state;
	num = state = 0;
	i = v = 1;

	makeSodoku();

	state = outputSodoku(i, v, state);

	do {

		printf("Gebe den Wert, den Reihenindex und Spaltenindex an: ");
		scanf("%d,%d,%d", &num, &i, &v);
		while(num > 9 || num < 0 || i > 9 || i < 1 || v > 9 || v < 1) {
			printf("Du kannst nur Werte zwischen 1 und 9 wählen. Versuche erneut: ");
			scanf("%d,%d,%d", &num, &i, &v);
		}
		while(checkSodoku(num, i, v) == 0) {
			printf("Du hast einen Fehler gemacht. Versuche erneut: ");
			scanf("%d,%d,%d", &num, &i, &v);
		}
		state = outputSodoku(i, v, state);

	} while(state == 0);

	
	return 0;
}
