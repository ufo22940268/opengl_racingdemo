#include <GL/glut.h>
#include <stdlib.h>
#include "util.h"

typedef struct {
    int x,
    int y,
    int color
} dot;

dot dots[MAX_DOTS_COUNT];
int dotCount = 0;

void initDots()
{
}

void updateDots() 
{
    if (dotCount == 0) {
	initDots();
    }
}
