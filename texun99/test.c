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

void testStack() 
{
    dot d1 = {.x = 1, .y = 1};
    dot d2 = {.x = 2, .y = 2};
    pushDot(&d1);
    pushDot(&d2);
    assert(popDot()->x == 2);
    assert(popDot()->x == 1);

    assert(popDot() == NULL);
}


int main() 
{
    testChooseEdge();
    testStack();
    printf("Test passed.\n");
    getchar();
}
