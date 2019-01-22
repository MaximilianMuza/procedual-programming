#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char vorname[20];
    char nachname[20];
    int matrikelnummer;
    char adresse[50];
    int pflichtkurse;
};

struct element {
    struct student s;
    struct element *prev;
    struct element *next;
};

struct element *alloc() {
    return malloc(sizeof(struct element));
}

struct element *top;
struct element *back;

int sortBubble(int *sort_array, int n) {
    for(int i = 0 ; i < n-1 ; i++){
      for(int j = 0 ; j < n-i-1 ; j++) {
        if(sort_array[j] > sort_array[j+1]) {
            int temp = sort_array[j];
            sort_array[j] = sort_array[j+1];
            sort_array[j+1] = temp;
        }
      }
    }
    return 0;
}

int add(struct student s) {
    if (top == NULL) {
        top = alloc();
        top->s = s;
        top->prev = NULL;
        back = top;
        back->s = s;
        back->next = NULL;
    }
    else {
        back->next = alloc();
        if (back->next == NULL) {
            return 0;
        }
        back->next->prev = back;
        back = back->next;
        back->s = s;
        back->next = NULL;
    }
    return 1;
}

void removeElement(int n) {
    struct element *current = top;
    int i = 1;
    while (current != NULL) {
        if (i == n) {
            current->next->prev = current->prev;
            current->prev->next = current->next;
            free(current);
            return;
        }
        current = current->next;
        i++;
    }
    return;
}

void printStudent(struct student *s) {
    printf("%s\n%s\n%d\n%s\n%d\n\n", s->vorname, s->nachname, s->matrikelnummer,s->adresse, s->pflichtkurse);
}

void changeDir() {
    struct element *current = top;
    top = back;
    back = current;
    while(current != NULL){
        struct element *tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }
}

int printList() {
    struct element *current = top;
    while (current != NULL){
        printStudent(&current->s);
        current = current->next;
    } 
    printf("________________________________________\n\n");
    return 0;
}

int main() {
    add((struct student){ "Hanny", "Musterfrau", 22222, "Am Schwarzenberg-Campus 3", 4 });
    add((struct student){ "Dirk", "Schmidt", 44444, "Kasernenstrasse 12", 2 });
    add((struct student){ "Lisa", "Lustig", 66666, "Denickestrasse 15", 8 });
    add((struct student){ "Anja", "Denise", 88888, "Reeperbahn 834", 6 });
    add((struct student){ "Katha", "Schmidt", 99999, "Hamburger Berg 9324", 6 });

    printList();
    removeElement(3);
    printList();

    changeDir();
    printList();

    return 0;
}
