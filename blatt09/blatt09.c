#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    char nachname[30];
    int matrikelnummer;
    char adresse[80];
    int pflichtkurse;
}student;

student person[] = {
    {"Anna", "Musterfrau", 22222, "Am Schwarzenberg-Campus 3", 4},
    {"Hans", "Peter", 44444, "Kasernenstrasse 12", 2},
    {"Lisa", "Lustig", 66666, "Denickestrasse 15", 8}
};

void ausgabe(student *person) {
    printf("%s, %s, %d, %s, %d\n", person->name, person->nachname, person->matrikelnummer, person->adresse, person->pflichtkurse);
}

void tausch(student *p1, student *p2) {
    student tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main() {
    for(int i = 0; i < 3; i++) {
        ausgabe(person+i);
    }
    printf("\n");
    tausch(person, person+2);
    for(int i = 0; i < 3; i++) {
        ausgabe(person+i);
    }
}
