#include <stdio.h>
#include <assert.h>
#include "types.h"

dot *dots[MAX_DOTS_COUNT];
int top = 0;

void pushDot(dot *d)
{
    assert(top < MAX_DOTS_COUNT);
    dots[top ++] = d;
}

dot* popDot()
{
    if (top == 0) {
        return NULL;
    } else {
        return dots[-- top];
    }
}

int dotStackSize()
{
    assert(top >= 0);
    return top;
}
