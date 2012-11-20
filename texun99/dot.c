#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "util.h"

const int PROFILE = 1;

extern float planeX;
extern float planeY;

extern int speed;
extern int dotCount;

void chooseEdge(int *x, int *y)
{
    extern int global_seed;

    int switcher[4][2] = {{1, 0}, {0, 1}, {1, 0}, {0, 1}};
    int base[4][2] = {{-100, -100}, {100, -100}, {-100, 100}, {-100, -100}};

    //Segment denote every edge of rectangle.
    int segmentIndex = global_seed/4%4;
    *x = base[segmentIndex][0] + switcher[segmentIndex][0]*200*timeRandf();
    *y = base[segmentIndex][1] + switcher[segmentIndex][1]*200*timeRandf();
}

bool isRightAngle(int x, int y, float angle) 
{
    return pow(x, 2) + pow(y, 2) >= pow(x + cos(angle), 2) + pow(y + sin(angle), 2);
}

dot* createDotFromEdge()
{
    dot* d = (dot*)malloc(sizeof(dot));
    int x, y;
    
    //Choose position.
    chooseEdge(&x, &y);

    //Choose vector.
    float angle = timeRand();
    if (!isRightAngle(x, y, angle)) {
        angle += M_PI;
    }

    d->x = x;
    d->y = y;
    d->angle = angle;
    return d;
}

void updatePosition()
{
    linked_node *cur = getHeaderNode();
    while (cur) {
        dot *d = cur->dot;
        d->x += speed*cos(d->angle);
        d->y += speed*sin(d->angle);
        if (abs(d->x) > 100 || abs(d->y) > 100) {
            deleteDot(d);
        }
        cur = cur->next;
    }
}

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
    linked_node *cur = getHeaderNode();
    while (cur) {
        dot *d = cur->dot;
        drawDot(d);
        cur = cur->next;
    }
}

void addNewDots(int cnt) 
{
    int i;
    for (i = 0; i < cnt; i ++) {
        dot* d = createDotFromEdge(i);
        insertDot(d);
    }
}

void updateDots() 
{
    int cnt = nodesSize();
    if (cnt < dotCount) {
        addNewDots(dotCount - cnt);
    }

    updatePosition();
}

bool isCollision() 
{
    linked_node *cur = getHeaderNode();
    while (cur) {
        dot* d = cur->dot;
        /*printf("x %d, y %d, planeX %f, planeY %f\n", d->x, d->y, planeX, planeY);*/
        if (distant(d->x, d->y, planeX, planeY) <= PLANE_SIZE) {
            return true;
        }
        cur = cur->next;
    }

    return false;
}

void dotToString(dot* d)
{
    if (d == NULL) {
        printf("null\n");
    } else {
        printf("x: %d, y: %d, angle %f\n", d->x, d->y, d->angle);
    }
}
