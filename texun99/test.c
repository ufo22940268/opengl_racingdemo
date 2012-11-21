#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <assert.h>
#include "util.h"

int gameStatus = STATUS_NORMAL;

extern float planeX;
extern float planeY;
extern int speed;
extern int dotCount;
extern int keyStatus;

void testChooseEdge()
{
    /*int x, y;*/

    /*int i = 1;*/
    /*chooseEdge(&x, &y);*/
    /*assert(y == -100);*/
    /*assert(x <= 100 && x >= -100);*/

    /*i = 4;*/
    /*chooseEdge(&x, &y);*/
    /*assert(x == 100);*/
    /*assert(y <= 100 && y >= -100); */

    /*i = 8;*/
    /*chooseEdge(&x, &y);*/
    /*assert(y == 100);*/
    /*assert(x <= 100 && x >= -100); */

    /*i = 12;*/
    /*chooseEdge(&x, &y);*/
    /*assert(x == -100);*/
    /*assert(y <= 100 && y >= -100); */

    int i;
    for (i = 1; i < 10; i ++) {
        dot* d = createDotFromEdge();

        double dis1 = distant(d->x, d->y, 0, 0);
        double dis2 = distant(d->x + cos(d->angle), d->y + sin(d->angle), 0, 0);
        assert(dis1 >= dis2);
    }
}

bool equalsX(int* xs) 
{
    linked_node *node = getHeaderNode();
    assert(node != NULL);
    while (node) {
        if (node->dot->x != *xs) {
            return false;
        }
        
        xs ++;
        node = node->next;
    }
    return true;
}

void testLinkedDots()
{
    //Test insert.
    dot *dot1 = (dot*)malloc(sizeof(dot));
    dot *dot2 = (dot*)malloc(sizeof(dot));
    dot *dot3 = (dot*)malloc(sizeof(dot));
    dot *dot4 = (dot*)malloc(sizeof(dot));
    dot1->x = 1;
    dot2->x = 2;
    dot3->x = 3;
    dot4->x = 4;
    insertDot(dot1);
    insertDot(dot2);
    insertDot(dot3);
    insertDot(dot4);
    assert(nodesSize() == 4);

    int xs[] = {4, 3, 2, 1};
    assert(equalsX(xs));

    //Test delete.
    assert(deleteDot(dot3));
    assert(nodesSize() == 3);
    int xs2[] = {4, 2, 1};
    assert(equalsX(xs2));

    assert(deleteDot(dot4));
    int xs3[] = {2, 1};
    assert(equalsX(xs3));

    //Test dot size.
    freeAllNodes();
    assert(nodesSize() == 0);
}

void testRand()
{
    float fr1 = timeRandf();
    float fr2 = timeRandf();
    assert(fr1 != fr2);
    assert(fr1 <= 1 && fr1 >= 0);
    assert(fr2 <= 1 && fr2 >= 0);
}

void testMoving()
{
    freeAllNodes();
    
    //Set up.
    dot* d1 = (dot*)malloc(sizeof(dot));
    d1->x = 1;
    d1->y = 1;
    dot* d2 = (dot*)malloc(sizeof(dot));
    d2->x = 2;
    d2->y = 2;
    
    freeAllNodes();
    insertDot(d1);
    insertDot(d2);

    planeX = 1;
    planeY = 1;
    assert(isCollision());

    planeX = 2;
    planeY = 2 + PLANE_SIZE;
    assert(isCollision());

    planeX = 2;
    planeY = 2 + PLANE_SIZE + 1;
    assert(!isCollision());
}

void testUtils() 
{
    double d1 = distant(1, 0, 0, 0);
    assert(d1 == 1);
    
    d1 = distant(2, 0, 0, 0);
    assert(d1 == 2);
}

void testUpdate()
{
    resetTimeData();

    updateTimeData();
    speed = SPEED_UNIT;
    dotCount = DOT_UNIT;
    updateTimeData();
    speed = SPEED_UNIT*2;
    dotCount = DOT_UNIT*2;

    resetTimeData();
    speed = 0;
    dotCount = 0;
}

void testKeyboard()
{
    pressKey(KEY_UP);
    assert(keyStatus == FLAG_UP);
    assert(getPlaneDirection() == DIRECTION_UP);

    resetKeyStatus();
    pressKey(KEY_UP);
    pressKey(KEY_LEFT);
    assert(getPlaneDirection() == DIRECTION_LEFT_UP);
    pressKey(KEY_RIGHT);
    assert(getPlaneDirection() == DIRECTION_LEFT_UP);
    pressKey(KEY_DOWN);
    assert(getPlaneDirection() == DIRECTION_VOID);
    releaseKey(KEY_UP);
    assert(getPlaneDirection() == DIRECTION_LEFT_DOWN);
    
    resetKeyStatus();
    assert(keyStatus == FLAG_VOID);
    assert(getPlaneDirection() == DIRECTION_VOID);
}

void testBend()
{
    int i;
    planeX = 1;
    planeY = 1;
    for (i = 0; i < 10; i ++) {
        printf("%d\n", i);
        dot d = {.x=timeRand(), .y=timeRand(), .angle=timeRand()};
        float oldAngle = d.angle;
        bendAngle(&d);
        float newAngle = d.angle; 
        assert(oldAngle != newAngle);

        int d1 = distant(planeX, planeY, d.x + cos(oldAngle), d.y + sin(oldAngle));
        int d2 = distant(planeX, planeY, d.x + cos(newAngle), d.y + sin(newAngle));
        assert(d1 > d2);
    }
}

void testC()
{
    int color = 0x66ccff;
    color = (color&0xff0000) >> 16;
    assert(color == 0x66);
}


int main() 
{
    testChooseEdge();
    testLinkedDots();
    testRand();
    testMoving();
    testUtils();
    testUpdate();
    testKeyboard();
    testBend();

    //One shot test.
    testC();

    printf("Test passed.\n");

    getchar();
    return 0;
}
