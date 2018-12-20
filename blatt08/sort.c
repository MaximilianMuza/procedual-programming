#include <stdio.h>
#include "sort.h"

int sortBubble(int *sort_array, int n) {
    for (int v = 0; v < n; n++){
        for (int i = 0; i < n - v; i++){
            if (sort_array[i] > sort_array[i+1]){
                int tmp = sort_array[i];
                sort_array[i] = sort_array[i+1];
                sort_array[i+1] = tmp;
            }
        }
    }
    // for(int j = 0; j < n; n++) {
    //     printf("%d\n", j);
    // }
    return 0;
}
int sortMerge(int *sort_array, int n) {
    return 0;
}
