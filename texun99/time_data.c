#include <stdio.h>
#include "util.h"

extern int updateCount;

int speed;
int dotCount = 5;

void updateTimeData()
{
    speed += SPEED_UNIT;
    dotCount += DOT_UNIT;
}

//TODO Reset other values.
void resetTimeData()
{
    speed = 0;
    dotCount = 0;
}
