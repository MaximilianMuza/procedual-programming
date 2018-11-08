
#include <stdio.h>
#include <stdint.h>

int main() {

  int num, i;
  num = 24;
  printf("Programm zur Ausgabe der Teiler einer Zahl\n");

  for(i = (num/2); i > 1; i--) {

    if(num%i == 0) {

      printf("%d\n", i);

    }

  }

  return 0;

}
