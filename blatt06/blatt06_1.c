#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "libBMP.h"

int w = 1000, h = 1000; //Bildgroesse
int xMin = -5, xMax = 5, yMin = -10, yMax = 10;
uint32_t *img;

int createImage(uint32_t *image, int width, int height, uint32_t color) {
    img = malloc(w*h * sizeof(uint32_t));
    if (img == NULL) {
        printf("Error allocating memory!");
        return 0;
    }
    for (int i = 0; i < w*h; i++) {
        img[i] = color;
    }
    bmp_create("Image.bmp", img, w, h);
    return 1;
}

double toMath(int x, int y, double *m_x, double *m_y) {
    
    *m_x = (double)(xMin + (double)x*(xMax-xMin)/w);
    *m_y = (double)(yMin + (double)(h-y) * (yMax - yMin)/h);
    return *m_x;
}

int toBMP(double m_x, double m_y, int *x, int *y) {
    *x = (m_x - xMin)*w / (xMax - xMin);
    *y = h-(m_y - yMin)*h / (yMax - yMin);
    return *x;
}

int drawPixel(int x, int y, uint32_t color) {
    if (x >= w || x < 0 || y >= h || y < 0)
        return 0;
    img[x + y * w] = color;
    return 1;
}

int main() {
    if (!createImage(img, w, h, COLOR_WHITE)) {
        printf("Image could not be created!");
    }
    else {
        bmp_create("Image.bmp", img, w, h);
        
        free(img);
    }
    
    return 0;
}
