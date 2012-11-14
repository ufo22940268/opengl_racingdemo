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
    assert(y == 0);
    assert(x <= 100 && x >= 0);

    i = 4;
    chooseEdge(i, &x, &y);
    assert(x == 100);
    assert(y <= 100 && y >= 0); 

    i = 8;
    chooseEdge(i, &x, &y);
    assert(y == 100);
    assert(x <= 100 && x >= 0); 

    i = 12;
    chooseEdge(i, &x, &y);
    assert(x == 0);
    assert(y <= 100 && y >= 0); 
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

    int xs[] = {4, 3, 2, 1};
    assert(equalsX(xs));

    //Test delete.
    assert(deleteDot(dot3));
    int xs2[] = {4, 2, 1};
    assert(equalsX(xs2));

    assert(deleteDot(dot4));
    int xs3[] = {2, 1};
    assert(equalsX(xs3));
}

void testC()
{
    int a = 1;
    int* i = &a;
    assert(i == i);
}


int main() 
{
    testChooseEdge();
    testLinkedDots();
    testC();
    printf("Test passed.\n");
    getchar();
}
