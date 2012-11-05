#include <stdlib.h>
#include "util.h"

float planeX = 0;
float planeY = 0;

void drawPlane() 
{
    glPushMatrix();
    glTranslatef(planeX, planeY, 0);
    drawCircle(PLANE_SIZE);
    glPopMatrix();
}

void movePlane(float x, float y)
{
    planeX += x;
    planeY += y;
}

void movePlaneInDirection(char key)
{
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
