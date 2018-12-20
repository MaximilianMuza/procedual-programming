/**
 * Prozedurale Programmierung
 *
 * Sudoku
 */

// "\x1B" ist der Hexadezimalcode fuer ESC (escape)
// siehe https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#define COLOR_RESET  printf("\x1B[0m")
#define COLOR_RED    printf("\x1B[31m")
#define COLOR_GREEN  printf("\x1B[32m")
#define COLOR_YELLOW printf("\x1B[33m")
#define COLOR_CYAN   printf("\x1B[36m")

#include <stdio.h>

/* Loesung:
int SUDOKU[9][9] = {
  {4,1,3,8,6,5,2,9,7},
  {9,5,6,2,3,7,4,8,1},
  {2,8,7,4,9,1,5,3,6},
  {8,6,2,9,7,3,1,5,4},
  {3,4,1,5,8,6,9,7,2},
  {7,9,5,1,4,2,3,6,8},
  {1,3,8,6,5,4,7,2,9},
  {5,2,9,7,1,8,6,4,3},
  {6,7,4,3,2,9,8,1,5}
};
*/

const int SUDOKU[9][9] = {
  {4,1,0,0,6,5,0,0,7},
  {0,0,6,0,0,7,4,8,0},
  {2,0,7,4,9,0,0,0,6},
  {0,6,0,0,7,0,1,0,0},
  {3,0,1,5,0,0,0,7,2},
  {0,9,0,0,4,2,3,0,8},
  {1,0,8,6,0,0,0,2,9},
  {0,2,0,0,1,8,6,4,0},
  {6,0,0,3,0,0,0,1,0}
};

int BOARD[9][9];  // Spielfeld

/**
 * Prueft, ob alle drei Sudoku-Regeln auf dem Spielfeld eingehalten wurden.
 * Stoppt beim erster erkannter Regelverletzung.
 *
 * show_hints - Wenn ungleich 0, Ausgabe von Fehlermeldungen.
 *
 * Rueckgabe 1, wenn alle Regeln eingehalten, sonst 0.
 */
int check_board(int show_hints) {
  for (int val = 1; val <= 9; val++) {
    int col_count[9] = {0,0,0,0,0,0,0,0,0};
    int square_count[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    for (int row = 0; row < 9; row++) {
      int row_count = 0;
      for (int col = 0; col < 9; col++) {
        if (BOARD[row][col] == val) {
          if (++row_count > 1) {
            if (show_hints) {
              COLOR_RED;
              printf("\n  --> Fehler in (%d/%d): ", row + 1, col + 1);
              printf("die %d kommt mehrfach in der Zeile vor!\n", val);
              COLOR_RESET;
            }
            return 0;
          }
          if (++col_count[col] > 1) {
            if (show_hints) {
              COLOR_RED;
              printf("\n  --> Fehler in (%d/%d): ", row + 1, col + 1);
              printf("die %d kommt mehrfach in der Spalte vor!\n", val);
              COLOR_RESET;
            }
            return 0;
          }
          if (++square_count[row / 3][col / 3] > 1) {
            if (show_hints) {
              COLOR_RED;
              printf("\n  --> Fehler in (%d/%d): ", row + 1, col + 1);
              printf("die %d kommt mehrfach im Quadrat vor!\n", val);
              COLOR_RESET;
            }
            return 0;
          }
        }
      }
    }
  }
  return 1;
}


/**
 * Gibt das gesamte Spielfeld auf dem Bildschirm aus.
 */
void print_board() {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("Steuerung:\n");
  printf("  Beenden:  \x1B[31m1337             \x1B[0m + ENTER\n");
  printf("  Spielzug: \x1B[36mZeile\x1B[32mSpalte\x1B[0mZiffer + ENTER\n\n");
  COLOR_GREEN;
  printf("     1  2  3   4  5  6   7  8  9\n");
  COLOR_RESET;
  printf("   +---------+---------+---------+\n");
  for (int row = 0; row < 9; row++) {
    COLOR_CYAN;
    printf(" %d ", row + 1);
    COLOR_RESET;
    printf("|");
    for (int col = 0; col < 9; col++) {
      if (BOARD[row][col] == 0) {
        printf("   ");
      } else {
        if (SUDOKU[row][col] != 0) {
          COLOR_YELLOW;
        }
        printf(" %d ", BOARD[row][col]);
        COLOR_RESET;
      }
      if ((col + 1) % 3 == 0) {
        printf("|");
      }
    }
    printf("\n");
    if ((row + 1) % 3 == 0) {
      printf("   +---------+---------+---------+\n");
    }
  }
}

/**
 * Hauptfunktion
 */
int main() {
  // Kopiere das original SUDOKU ins Spielfeld.
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      BOARD[row][col] = SUDOKU[row][col];
    }
  }

  // Erste Ausgabe
  print_board();
  printf("\n\n\nEingabe:  ");

  // Spielhauptschleife
  int input = 0; // Gerade verarbeitete Eingabe
  char buf[100]; // Eingabepuffer
  while (1) {
    fgets(buf, 100, stdin);    // Lese in Eingabepuffer ein
    sscanf(buf, "%d", &input); // scanf("%d", &input);
    if (input == 1337) {
      break;  // Verlasse Endlosschleife --> Spielende
    }

    // Pruefe auf gueltige Eingaben
    int row = (input % 1000) / 100; // Zeile  [1..9]
    int col = (input %  100) /  10; // Spalte [1..9]
    int val = (input %   10);       // Ziffer [0..9]
    if ((input > 999) || (input < 100) || (row == 0) || (col == 0)) {
      print_board();
      COLOR_RED;
      printf("\n  --> Falsche Eingabe!!\n");
      COLOR_RESET;
      printf("\nEingabe:  ");
      continue;
    }

    // Gueltige Werte fuer row, col, val erhalten.
    // Pruefe, ob Feld spielbar ist.
    if (SUDOKU[row - 1][col - 1] != 0) {
      print_board();
      COLOR_RED;
      printf("\n  Das Setzen von Feld (%d/%d) ist verboten!\n", row, col);
      COLOR_RESET;
      printf("\nEingabe:  ");
      continue;
    }

    // Spielzug erlaubt
    BOARD[row - 1][col - 1] = val;
    print_board();
    if (check_board(1)) {
      printf("\n\n");  // Gebe Leerzeilen statt Fehlermeldung aus.
    }
    printf("\nEingabe:  ");
  }

  COLOR_RED;
  printf("\n  --> Spiel beendet.\n\n\n");
  COLOR_RESET;

  return 0;
}
