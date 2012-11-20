#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "util.h"

int global_seed = 0;

extern long startTime;

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

void drawString(int x, int y, char* str) 
{
    glRasterPos2i(x, y);

    int i;
    for (i = 0; i < strlen(str); i ++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
    }
}

int timeRand()
{
    srand(time(NULL) * global_seed);
    global_seed = (global_seed + 1)%100000;
    return rand();
}

float timeRandf()
{
    int ri = timeRand();
    return (float)(ri%100)/100;
}

void setColor(int color) 
{
    float r = (float)((color&0xff0000)>>16)/255;
    float g = (float)((color&0x00ff00)>>8)/255; 
    float b = (float)((color&0x0000ff)>>0)/255;
    glColor3f(r, g, b);
}

double distant(int xa, int ya, int xb, int yb) 
{
    return sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
}
