#include <stdlib.h>
#include "util.h"

extern int gameStatus;

float planeX = 0;
float planeY = 0;

void drawPlane() 
{
    glPushMatrix();
    glTranslatef(planeX, planeY, 0);
    setColor(0x66ccff);
    drawCircle(PLANE_SIZE);
    glPopMatrix();
}

void movePlane(int x, int y)
{
    planeX += x;
    planeY += y;
}

void movePlaneInDirection(char key)
{
    if (gameStatus == STATUS_FINISHED) {
        return;
    }

    switch (key) {
	case KEY_UP:
	    movePlane(0, MOVE_SIZE);
	    break;
	case KEY_DOWN:
	    movePlane(0, -MOVE_SIZE);
	    break;
	case KEY_LEFT:
	    movePlane(-MOVE_SIZE, 0);
	    break;
	case KEY_RIGHT:
	    movePlane(MOVE_SIZE, 0);
	    break;
    }
}
