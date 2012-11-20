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

void movePlaneInDirection(int direction)
{
    if (gameStatus == STATUS_FINISHED) {
        return;
    }

    switch (direction) {
	case DIRECTION_UP:
	    movePlane(0, MOVE_SIZE);
	    break;
	case DIRECTION_DOWN:
	    movePlane(0, -MOVE_SIZE);
	    break;
	case DIRECTION_LEFT:
	    movePlane(-MOVE_SIZE, 0);
	    break;
	case DIRECTION_RIGHT:
	    movePlane(MOVE_SIZE, 0);
	    break;
	case DIRECTION_LEFT_UP:
	    movePlane(-MOVE_SIZE, MOVE_SIZE);
	    break;
	case DIRECTION_RIGHT_UP:
	    movePlane(MOVE_SIZE, MOVE_SIZE);
	    break;
	case DIRECTION_LEFT_DOWN:
	    movePlane(-MOVE_SIZE, -MOVE_SIZE);
	    break;
	case DIRECTION_RIGHT_DOWN:
	    movePlane(MOVE_SIZE, -MOVE_SIZE);
	    break;
    }
}
