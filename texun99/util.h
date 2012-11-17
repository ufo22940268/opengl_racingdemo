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

void setColor(int color);

void updateDots();
void chooseEdge(int i, int *x, int *y);

int timeRand(int i);
float timeRandf(int s); 

void dotToString(dot* d);

linked_node* getHeaderNode();
void insertDot(dot *dot);
bool deleteDot(dot *dot);
int nodesSize();
void freeAllNodes();
