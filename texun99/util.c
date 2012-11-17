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
    srand(time(NULL) * (i + 1));
    return rand();
}

float timeRandf(int s)
{
    int ri = timeRand(s);
    return (float)(ri%100)/100;
}

void setColor(int color) 
{
    float r = (float)((color&0xff0000)>>16)/255;
    float g = (float)((color&0x00ff00)>>8)/255; 
    float b = (float)((color&0x0000ff)>>0)/255;
    glColor3f(r, g, b);
}
