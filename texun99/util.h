#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "types.h"

float toRadians(int degree);
void drawCircle(float r);
void drawPlane();
void movePlane(float x, float y);
void movePlaneInDirection(char key);

void updateDots();
void chooseEdge(int i, int* x, int* y);

int timeRand();

dot* popDot();
void pushDot(dot *d);
int dotStackSize();
void dotToString(dot* d);
