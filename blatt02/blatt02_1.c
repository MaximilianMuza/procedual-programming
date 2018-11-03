
#include <stdio.h>
#include <stdint.h>

int main() {
	
	// Verschiedene Variablen werden definiert und es wird für diese Platz im Speicher reserviert 
	// Der Datentyp int16_t hat die Bitlänge 16
  int16_t a_16, b_16, c_16;
  	// Der Datentyp int32_t hat die Bitlänge 32
  int32_t a_32, b_32, c_32;
  	// Der Datentyp uint16_t hat die Bitlänge 16
  uint16_t a_u16, b_u16, c_u16;
  	
  	// Verschiedene Variablen bekommen den Wert 222222 zugewiesen
  	// Sowohl die Variablen der Bitlänge 16 als auch die mit der Bitlänge 32 stellen den Wert im Binärsystem gleich dar
  b_16 = a_16 = 22222;
  b_32 = a_32 = 22222;

  	// Ausführen einer Addition in Rücksichtsnahme des Zweierkomplements
  	// Zuweisen des Ergebnisses zu c_32
  c_32 = a_32 + b_32;
  	// Ausführen einer Addition in Rücksichtsnahme des Zweierkomplements
  	// Zuweisen des Ergebnisses zu c_32
  	// Wegen Wrap-Around unterscheidet sich das Ergebnis zu dem von c_32 und ist negativ 
  c_16 = a_16 + b_16;

  	// Ausgeben der Rechnungen als String
  	// Die Platzhalter %d bzw. %hd werden durch die Werte der Variablen der Reihe nach eingesetzt
  	// Es wird ein String ausgegeben, der den Rechnungsweg und die Lösung darstellt
  printf("a_32 + b_32 = %d + %d = %d \n\n", a_32, b_32, c_32);
  printf("a_16 + b_16 = %hd + %hd = %hd\n\n", a_16, b_16, c_16);

  	// Ausführen von einer Addition bei der ein Integer der Bitlänge 16 mit einem der Bitlänge 32
  	// Das Ergebnis wird einem UInteger mit der Länge 16 zugewiesen 
  a_u16 = a_16 + c_32;
  	// Ausgeben der obigen Rechnung durch Ersetzen der Platzhalter mit den Werten der Variablen
  printf("a_16 + c_32 = %hd + %d = %hu\n\n", a_16, c_32, a_u16);

  	// Neuzuweisung zweier Integer
  a_u16 = 2222;
  b_u16 = -222;
  	// Ausführen einer Addition zweier UInterger mit der gleichen Bitlänge 16 
  c_u16 = a_u16 + b_u16;
  // Ausgeben der obigen Rechnung
  printf("a_u16 + b_u16 = %hu(=%hd) + %hu(=%hd) = %hu(=%hd)\n\n", a_u16,
         a_u16, b_u16, b_u16, c_u16, c_u16);

  	// Neuzuweisung zweier Integer der Bitlänge 32
  a_32 = 555;
  b_32 = 1001;
  	// Ausführung einer Multiplikation der beiden obigen Werte
  	// Zuweisung des Ergebnisses zur Variable c_32
  	// Zuweisung des Wertes von c_32 zu c_16
  c_16 = c_32 = a_32 * b_32;
  	// Ausgeben des Rechenweges als String
  	// Kein Einsetzen von Variablen 
  printf("c_16 = c_32 = a_32 * b_32\n");
  	// Ausgeben der Rechnung als String durch Einsetzen der Variablen
  printf("%hd = %d = %d * %d\n\n", c_16, c_32, a_32, b_32);
  
  	// Ausführen einer Multiplikation zweier Variablen der Bitlänge 32
  	// Zuweisen des Ergebnisses zu einer Variable der Bitlänge 16
  	// Zuweisen des Wertes von c_16 zu c_32 mit der Bitlänge 32
  c_32 = c_16 = a_32 * b_32;
  	// Ausgeben des Rechenweges
  printf("c_32 = c_16 = a_32 * b_32\n");
  	// Ausgeben der Rechnung durc Einsetzen der Variablen
  printf("%d = %hd = %d * %d\n\n", c_32, c_16, a_32, b_32);

  return 0;
}
