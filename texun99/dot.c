#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "util.h"

const int PROFILE = 1;

typedef struct {
    int x;
    int y;
    int color;

    /*
     * vx, vy refers to the vector of the dot. every time updates
     * dots just need to add the vx and vy to x and y
     */
    int vx;
    int vy;
} dot;

dot dots[MAX_DOTS_COUNT];
int dotsCount = 0;

dot createDotFromEdge(int i)
{
    dot d;
    
    //Choose position.
    int x = 100;
    int y = i*5%100;

    //Choose vector.
    /*srand(i);*/
    int k = 0 - x < 0 ? -1 : 1;
    int vx = timeRand()%5*k;
    /*srand(i + 1);*/
    k = 0 - y < 0 ? -1 : 1;
    int vy = timeRand()%5*k;

    d.x = x;
    d.y = y;
    d.vx = vx;
    d.vy = vy;
    return d;
}

void initDots()
{
    int i;
    for (i = 0; i < TEST_DOTS_COUNT; i ++) {
        dots[i] = createDotFromEdge(i);
        dotsCount += 1;
    }
}

void updatePosition()
{
    int i;
    for (i = 0; i < dotsCount; i ++) {
        dot *d = &dots[i];
        d->x = (d->x + d->vx)%WINDOW_WIDTH;
        d->y = (d->y + d->vy)%WINDOW_HEIGHT;
    }
}

//TODO Dots doesn't appear in screen, probably because the clear color buffer bit instruction
//in display method has clear the dots.
void drawDot(dot *d)
{
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
    if (dotsCount == 0) {
	initDots();
    } else {
        updatePosition();
    }

    if (PROFILE) {
        test();
    }
    drawDots();
}
