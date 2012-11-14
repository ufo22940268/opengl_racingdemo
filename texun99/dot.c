#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "util.h"

const int PROFILE = 1;

dot dots[MAX_DOTS_COUNT];
int dotsCount = 0;

dot* createDotFromEdge(int i)
{
    dot* d = (dot*)malloc(sizeof(dot));
    int x, y;
    
    //Choose position.
    chooseEdge(i, &x, &y);
    /*int x = 100;*/
    /*int y = i*5%100;*/

    //Choose vector.
    int k = (0 - x < 0 ? -1 : 1);
    int vx = timeRand(i)%5*k;
    k = (0 - y < 0 ? -1 : 1);
    int vy = timeRand(i)%5*k;

    d->x = x;
    d->y = y;
    d->vx = vx;
    d->vy = vy;
    return d;
}

void initDots()
{
    /*while (dotStackSize() <= 5) {*/
        /*dot* d = createDotFromEdge(dotStackSize());*/
        /*pushDot(d);*/
    /*}*/
}

void removeDot(dot* d) 
{
    free(d);
}

void updatePosition()
{
/*    dot* d;*/
    /*while ((d = popDot()) != NULL) {*/
        /*[>dotToString(d);<]*/
        /*d->x = d->x + d->vx;*/
        /*d->y = d->y + d->vy;*/
        /*if (abs(d->x) > 100 || abs(d->y) > 100) {*/
            /*removeDot(d);*/
        /*} else {*/
            /*pushDot(d);*/
        /*}*/
    /*}*/
}

void drawDot(dot *d)
{
    //If the vector of dot equal to zero, then it means the dot
    //is static and it doesn't need to be drawn any more.
    if (d->vx == 0 && d->vy == 0) 
    {
        return;
    }

    glColor3f(1, 1, 1);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2i(d->x, d->y);
    glEnd();
}

void drawDots()
{
    int i;
    for (i = 0; i < dotsCount; i++) {
        drawDot(&dots[i]);
    }
}

void test() 
{
    int i;
    for (i = 0; i < dotsCount; i ++) {
        dot *d = &dots[i];
        printf("dot %d: x %d\ty %d\n", i, d->x, d->y);
    }
    printf("\n\n\n");
}

void updateDots() 
{
    updatePosition();
}

void dotToString(dot* d)
{
    if (d == NULL) {
        printf("null\n");
    } else {
        printf("x: %d, y: %d, vx %d, vy %d\n", d->x, d->y, d->vx, d->vy);
    }
}
