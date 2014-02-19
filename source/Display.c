#include <stdio.h>
#include "Alarm.h"

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

int display_alarms_in_zone(int zone)
{
    if(zone==1)
    {
        printf("    alarm 1 = %d\n\r",alarms.alarm1);
        printf("    alarm 2 = %d\n\r",alarms.alarm2);
        printf("    alarm 3 = %d\n\r",alarms.alarm3);
    }
    if(zone==2)
    {
        printf("    alarm 4 = %d\n\r",alarms.alarm4);
        printf("    alarm 5 = %d\n\r",alarms.alarm5);
        printf("    alarm 6 = %d\n\r",alarms.alarm6);
    }
    if(zone==3)
    {
        printf("    alarm 7 = %d\n\r",alarms.alarm7);
        printf("    alarm 8 = %d\n\r",alarms.alarm8);
        printf("    alarm 9 = %d\n\r",alarms.alarm9);
    }
    return 0;
}

int display()
{
    printf("\n\r");

    if(zones.zone1 == 1)
    {
        printf("zone 1 safe\n\r");
    }
    else
    {
        printf("zone 1 on fire\n\r");
        display_alarms_in_zone(1);
    }
    if(zones.zone2 == 1)
    {
        printf("zone 2 safe\n\r");
    }
    else
    {
        printf("zone 2 on fire\n\r");
        display_alarms_in_zone(2);
    }
    if(zones.zone3 == 1)
    {
        printf("zone 3 safe\n\r");
    }
    else
    {
        printf("zone 3 on fire\n\r");
        display_alarms_in_zone(3);
    }

    printf("\n\r");

    if(zones.zone1 == 1)
    {
        display_zone1_safe();
    }
    else
    {
        display_zone1_fire();
    }
    if(zones.zone2 == 1)
    {
        display_zone2_safe();
    }
    else
    {
        display_zone2_fire();
    }
    if(zones.zone3 == 1)
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
