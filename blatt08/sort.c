#include <stdio.h>
#include "sort.h"

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
int sortMerge(int *arr, int n) {
    if(n > 1) {

        int haelfte1[n/2];
        int haelfte2[(n + 1)/2];
        int i;
        for(i = 0; i < n/2; i++){
            haelfte1[i] = arr[i];
        }
        for(i = n/2; i < n; i++){
            haelfte2[i - n/2] = arr[i];
        }

        sortMerge(haelfte1,n/2);
        sortMerge(haelfte2,(n + 1)/2);

        int *pos1 = &haelfte1[0];
        int *pos2 = &haelfte2[0];
        for(i = 0; i < n; i++){
            if(*pos1 <= *pos2){
                arr[i] = *pos1;
                if (pos1 != &haelfte2[(n+1)/2 - 1]) { // pos1 nicht verändern, wenn der größte Wert mehrmals vorkommt
                    if(pos1 == &haelfte1[n/2 - 1]){
                        pos1 = &haelfte2[(n+1)/2 - 1];
                    }
                    else{
                        ++pos1;
                    }
                }
            }
            else{
                arr[i] = *pos2;
                if(pos2 == &haelfte2[(n + 1)/2 - 1]){
                    pos2 = &haelfte1[n/2 - 1];
                }
                else{
                    ++pos2;
                }
            }
        }
    }
    return 0;
}
