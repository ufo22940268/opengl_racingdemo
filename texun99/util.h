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
void movePlaneInDirection(int key);
void drawDots();
void drawString(int x, int y, char* str);
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
void bendAngle(dot* d);

void resetTimeData();
void updateTimeData();

bool isControllerKey(char key);
void controlPlane(char key);

void resetKeyStatus();
int getPlaneDirection();
void pressKey(char key);
void releaseKey(char key);

void controlPlaneRelease(char key);

void resetGame();

