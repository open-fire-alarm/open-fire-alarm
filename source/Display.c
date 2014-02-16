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

    if(zones.zone1 == 0)
    {
        display_zone1_safe();
    }
    else
    {
        display_zone1_fire();
    }
    if(zones.zone2 == 0)
    {
        display_zone2_safe();
    }
    else
    {
        display_zone2_fire();
    }
    if(zones.zone3 == 0)
    {
        display_zone3_safe();
    }
    else
    {
        display_zone3_fire();
    }

    printf("\n\r");

	return 0;
}

int display_zone1_safe()
{
    return 0;
}

int display_zone1_fire()
{
    return 0;
}

int display_zone2_safe()
{
    return 0;
}

int display_zone2_fire()
{
    return 0;
}

int display_zone3_safe()
{
    return 0;
}

int display_zone3_fire()
{
    return 0;
}
