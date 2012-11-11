#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "util.h"

float toRadians(int degree) 
{
    return degree;
}

void drawCircle(float r)
{
    int i;
    glBegin(GL_TRIANGLE_FAN);
    for (i = 0; i <= 360; i ++) {
        int ra = toRadians(i);
        glVertex2f(r*cos(ra), r*sin(ra));
    }
    glEnd();
}

int timeRand(int i)
{
    int s = time(NULL)%60;
    srand(s*i);
    return rand();
}

int timeRandRange(int i, int range)
{
    return timeRand(i)%range;
}

void chooseEdge(int s, int* x, int* y)
{
    int i;
    int segment = 16/4;

    int switcher[4][2] = {{1, 0}, {0, 1}, {1, 0}, {0, 1}};
    int base[4][2] = {{0, 0}, {100, 0}, {0, 100}, {0, 0}};

    int segmentIndex = s/4;

    *x = base[segmentIndex][0] + switcher[segmentIndex][0]*timeRandRange(s, 100);
    *y = base[segmentIndex][1] + switcher[segmentIndex][1]*timeRandRange(s, 100);
}
