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

int timeRand()
{
    int s = time(NULL)%60;
    srand(s);
    return rand();
}
