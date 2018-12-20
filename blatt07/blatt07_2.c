#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "libBMP.h"

int w = 2000, h = 2000;
int xMin = -2, xMax = 1, yMin = -1, yMax = 1;
int nMax = 96;
int zLimit = 2;
uint32_t *img;

int createImage(uint32_t color) {
    img = malloc(w*h * sizeof(uint32_t));
    if (img == NULL) {
        printf("Error allocating memory!");
        return 0;
    }
    for (int i = 0; i < w*h; i++) {
        img[i] = color;
    }
    bmp_create("Mandelbrot.bmp", img, w, h);
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

int set(double x, double iy, double zx, double iz, int n) {
    if (zx * zx + iz * iz >= zLimit * zLimit || n > nMax) {
        return n;
    }
    double i = iz;
    iz = 2 * zx*iz + iy;
    zx = zx * zx - i * i + x;
    return set(x, iy, zx, iz, ++n);
}

int mandelBrot() {
    double m_x, m_y;
    int n;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            n = set(toMath(x, y, &m_x, &m_y), m_y, 0, 0, 0);
            if(n<=5)
                drawPixel(x, y,COLOR_WHITE);
            else if(n<=10){
                drawPixel(x, y,COLOR_GREEN);
            }
            else if(n<=20){
                drawPixel(x, y,COLOR_BLUE);
            }
            else if(n<=nMax){
                drawPixel(x, y,COLOR_RED);
            }
            else
                drawPixel(x, y,COLOR_BLACK);

        }
    }
    return 0;
}

int main() {
    if (!createImage(COLOR_WHITE)) {
        printf("Image could not be created!");
    }
    else {
        mandelBrot();
        bmp_create("Mandelbrot.bmp", img, w, h);

        free(img);
    }
        
    return 0;
}
