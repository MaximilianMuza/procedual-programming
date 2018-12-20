#include <stdio.h>
#include <stdint.h>

uint8_t sudoku[9][9] = 
    {{4,1,0,0,6,5,0,0,7},
    {0,0,6,0,0,7,4,8,0},
    {2,0,7,4,9,0,0,0,6},
    {0,6,0,0,7,0,1,0,0},
    {3,0,1,5,0,0,0,7,2},
    {0,9,0,0,4,2,3,0,8},
    {1,0,8,6,0,0,0,2,9},
    {0,2,0,0,1,8,6,4,0},
    {6,0,0,3,0,0,0,1,0}};
uint16_t steps[11];

int printSudoku() {
    printf("     1 2 3   4 5 6   7 8 9\n");
    for (int y = 0; y < 9; y++) {
        if (y % 3 == 0) {
            printf("   +-------+-------+-------+\n");
        }
        printf(" %d ", y + 1);
        for (int x = 0; x < 9; x++) {
            if (x % 3 == 0) {
                printf("| ");
            }
            if (sudoku[x][y]== 0) {
                printf("  ");
            }
            else {
            printf("%d ", sudoku[x][y]);
            }
        }
        printf("|\n");
    }
    printf("   +-------+-------+-------+\n");
    return 0;
}

int writeVal(uint8_t x, uint8_t y, uint8_t val) {
    //check rule widthswise
    if (val != 0) {
        for (int i = 0; i < 9; i++) {
            if (sudoku[i][y] == val) return 0;
        }
        //check rule heightswise
        for (int i = 0; i < 9; i++) {
            if (sudoku[x][i] == val) return 0;
        }
        //check rule in square
        for (int i = y - (y % 3); i < y - (y % 3) + 3; i++) {
            for (int j = x - (x % 3); j < x - (x % 3) + 3; j++) {
                if (sudoku[j][i] == val && i != y && j != x) {
                    return 0;
                }
            }
        }
    }
    sudoku[x][y] = val;
    return 1;
}

int solve(int i){
    if (i >= 81) { return 1; }
    int x, y;
    for (; i < 82; i++) {
        if (i >= 81) return 1;
        if (!sudoku[i % 9][i / 9]) {
            x = i % 9;
            y = i / 9;
            break;      
        }
    }
    for (int j = 1; j <= 9; j++) {
        if (writeVal(x, y, j)) {
            if (solve(i))
                return 1;
            else
                writeVal(x, y, 0);
        }
    }
    return 0;
}

int main() {
    steps[0] = 0;
    char c[3];
    uint8_t oldVal;
    printSudoku();
    while ((c[0] = getchar()) != 'e') {
        if (c[0] >= '0' && c[0] <= '9') {
            c[1] = getchar();
            c[2] = getchar();
            oldVal = sudoku[c[0] - '0' - 1][c[1] - '0' - 1];
            if (!writeVal(c[0] - '0' - 1, c[1] - '0' - 1, c[2] - '0')) {
                printf("Denied\n");
            }
            else {
                int s;
                steps[steps[0] % 10 + 1] = s = (oldVal * 100) + ((c[1]-'0' - 1) * 10) + (c[0]-'0' - 1);
                steps[0]++;
                printf("s%d\n", s);
                printSudoku();
            }
        }
        else if (c[0] == 'r' && steps[0] > 0) {
            steps[0]--;
            int x, y, val;
            x = steps[steps[0] % 10 + 1] % 10;
            steps[steps[0] % 10 + 1] -= x;
            y = steps[steps[0] % 10 + 1] / 10 % 10;
            steps[steps[0] % 10 + 1] -= y*10;
            val = steps[steps[0] % 10 + 1] / 100 % 10;
            steps[steps[0] % 10 + 1] = 0;
            writeVal(x, y,val);
            printSudoku();
        }
        else if (c[0] == 's') {
            if (!solve(0)) {
                printf("No solution found!\n");
            }
            else {
                printSudoku();
            }
        }
        else
        {
            printf("Command not found\n");
        }
        while ((c[0] = getchar()) != '\n' && c[0] != EOF);
    }
    return 0;
}
