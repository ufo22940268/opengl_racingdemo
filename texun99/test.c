#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "util.h"

int main() 
{
    int i1 = timeRand();
    sleep(3);
    int i2 = timeRand();
    printf("i1: %d\ti2 %d\n", i1, i2);
    assert(i1 != i2);
}
