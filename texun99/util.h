#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "types.h"

#define SHUFFLE time(NULL)

float toRadians(int degree);
void drawCircle(float r);
void drawPlane();
void movePlane(int x, int y);
void movePlaneInDirection(char key);
void drawDots();
bool isCollision();

void setColor(int color);

void updateDots();
void chooseEdge(int *x, int *y);

int timeRand();
float timeRandf(); 
double distant(int xa, int ya, int xb, int yb);

void dotToString(dot* d);

linked_node* getHeaderNode();
void insertDot(dot *dot);
bool deleteDot(dot *dot);
int nodesSize();
void freeAllNodes();

dot* createDotFromEdge();


//Timer function test.
void resetTimeData();
void updateTimeData();
