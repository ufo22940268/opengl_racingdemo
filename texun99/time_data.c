#include <stdio.h>
#include "util.h"

#define INIT_SPEED 1
#define INIT_DOT_COUNT 5

extern int updateCount;

int speed = INIT_SPEED;
int dotCount = INIT_DOT_COUNT;

void updateTimeData()
{
    //Update speed.
    speed += SPEED_UNIT;
    speed %= 8;

    //Update dot count.
    dotCount += DOT_UNIT;
}

//TODO Reset other values.
void resetTimeData()
{
    speed = INIT_SPEED;
    dotCount = INIT_DOT_COUNT;
}
