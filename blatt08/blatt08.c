#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int input_val;
int *sort_array;
int n;
int arr_val;

int menu() {
    printf("\nMenü:\n");
    printf("1) Array-Groesse festlegen\n");
    printf("2) Zahlen von Tastatur einlesen\n");
    printf("3) Zufallszahlen erzeugen\n");
    printf("4) Bubblesort (downwards)\n");
    printf("5) Mergesort\n");
    printf("6) Programm beenden\n");
    printf("Bitte gebe deine Auswahl als Zahl ein: \n");
    scanf("%d", &input_val);

    return 0;
}
int allocateMemory() {
    printf("1) Bitte lege die Länge der zu sortierenden Elemente fest: ");
    scanf("%d", &n);
    /* allocate memory dynamically */
    sort_array = (int*)malloc(n * sizeof(int));
                    
    if(sort_array == NULL) {
        printf("Error - unable to allocate required memory\n");
    }
    return 0;
}

int main() {

    while(1) {

        menu();
        switch(input_val) {
            case 1:
                allocateMemory();
                break;
            case 2:
                for(int i = 0; i < n; i++) {
                    printf("Bitte gebe eine Zahl für einen Wert für den Array an: ");
                    scanf("%d", &arr_val);
                    sort_array[i] = arr_val;
                }
                for(int i = 0; i < n; i++) {
                    printf("%d\n", sort_array[i]);
                }
                break;
            case 3:
                printf("3) Es werden zufällige Werte für das Array generiert");
                for(int i = 0; i < n; i++) {
                    sort_array[i] = rand();
                }
                for(int i = 0; i < n; i++) {
                    printf("%d\n", sort_array[i]);
                }
                break;
            case 4:
                sortBubble(sort_array, n);
                for(int i = 0; i < n; i++) {
                    printf("%d\n", sort_array[i]);
                }
                break;
            case 5:
                sortMerge(sort_array, n);
                for(int i = 0; i < n; i++) {
                    printf("%d\n", sort_array[i]);
                }
                break;
            case 6:
                return 0;
        }
    }

    free(sort_array);
    return 0;
}
