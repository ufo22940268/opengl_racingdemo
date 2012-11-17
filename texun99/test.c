#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "util.h"

void testChooseEdge()
{
    int x, y;

    int i = 1;
    chooseEdge(i, &x, &y);
    assert(y == -100);
    assert(x <= 100 && x >= -100);

    i = 4;
    chooseEdge(i, &x, &y);
    assert(x == 100);
    assert(y <= 100 && y >= -100); 

    i = 8;
    chooseEdge(i, &x, &y);
    assert(y == 100);
    assert(x <= 100 && x >= -100); 

    i = 12;
    chooseEdge(i, &x, &y);
    assert(x == -100);
    assert(y <= 100 && y >= -100); 
}

bool equalsX(int* xs) {
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
    float fr1 = timeRandf(1);
    float fr2 = timeRandf(2);
    assert(fr1 != fr2);
    assert(fr1 <= 1 && fr1 >= 0);
    assert(fr2 <= 1 && fr2 >= 0);
}

void testC()
{
    int color = 0x66ccff;
    color = (color&0xff0000) >> 16;
    assert(color == 0x66);

    /*printf("%d\n", timeRand(1));*/
    /*printf("%d\n", timeRand(5));*/
}


int main() 
{
    testChooseEdge();
    testLinkedDots();
    testRand();

    //One shot test.
    testC();

    printf("Test passed.\n");

    getchar();
}
