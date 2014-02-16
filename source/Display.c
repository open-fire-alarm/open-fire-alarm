#include <stdio.h>
#include "Alarm.h"

int display()
{
    if(zones.zone1 == 0)
    {
        printf("zone 1 safe\n\r");
    }
    else
    {
        printf("zone 1 on fire\n\r");
    }
    if(zones.zone2 == 0)
    {
        printf("zone 2 safe\n\r");
    }
    else
    {
        printf("zone 2 on fire\n\r");
    }
    if(zones.zone3 == 0)
    {
        printf("zone 3 safe\n\r");
    }
    else
    {
        printf("zone 3 on fire\n\r");
    }
    printf("\n\r");
	return 0;
}
