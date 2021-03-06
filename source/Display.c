#include <stdio.h>
#include "Alarm.h"

/* Display.c */

int display_zones_active()
{
    if(get_zones_active1())
    {
        printf("zones 1 active\n\r");
    }
    else
    {
        printf("zones 1 desactive\n\r");
    }
    if(get_zones_active2())
    {
        printf("zones 2 active\n\r");
    }
    else
    {
        printf("zones 2 desactive\n\r");
    }
    if(get_zones_active3())
    {
        printf("zones 3 active\n\r");
    }
    else
    {
        printf("zones 3 desactive\n\r");
    }

    return 0;
}

int display_alarms_in_zone(int zone)
{
    if(zone==1)
    {
        printf("    alarm 1 = %d\n\r",get_alarm1());
        printf("    alarm 2 = %d\n\r",get_alarm2());
        printf("    alarm 3 = %d\n\r",get_alarm3());
    }
    if(zone==2)
    {
        printf("    alarm 4 = %d\n\r",get_alarm4());
        printf("    alarm 5 = %d\n\r",get_alarm5());
        printf("    alarm 6 = %d\n\r",get_alarm6());
    }
    if(zone==3)
    {
        printf("    alarm 7 = %d\n\r",get_alarm7());
        printf("    alarm 8 = %d\n\r",get_alarm8());
        printf("    alarm 9 = %d\n\r",get_alarm9());
    }
    return 0;
}

int display_the_situation()
{
    if(get_zones_active1())
    {
        if(get_zone1()) /* if zone n safe then print "zone n safe" else print zone n on fire and print all the alarms in the zone n */
        {
            printf("zone 1 safe\n\r");
        }
        else
        {
            printf("zone 1 on fire\n\r");
            display_alarms_in_zone(1);
        }
    }
    if(get_zones_active2())
    {
        if(get_zone2())
        {
            printf("zone 2 safe\n\r");
        }
        else
        {
            printf("zone 2 on fire\n\r");
            display_alarms_in_zone(2);
        }
    }
    if(get_zones_active3())
    {
        if(get_zone3())
        {
            printf("zone 3 safe\n\r");
        }
        else
        {
            printf("zone 3 on fire\n\r");
            display_alarms_in_zone(3);
        }
    }

    return 0;
}

int display_zone1_safe()
{
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|____________________|\n\r");

    return 0;
}

int display_zone1_fire()
{
    printf("|                    |\n\r");
    printf("|         )          |\n\r");
    printf("|        ) |          |\n\r");
    printf("|       / ) (        |\n\r");
    printf("|_______\(_)/________|\n\r");

    return 0;
}

int display_zone2_safe()
{
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|____________________|\n\r");

    return 0;
}

int display_zone2_fire()
{
    printf("|                    |\n\r");
    printf("|         )          |\n\r");
    printf("|        ) |         |\n\r");
    printf("|       / ) (        |\n\r");
    printf("|_______\(_)/________|\n\r");

    return 0;
}

int display_zone3_safe()
{
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|____________________|\n\r");

    return 0;
}

int display_zone3_fire()
{
    printf("|                    |\n\r");
    printf("|         )          |\n\r");
    printf("|        ) |         |\n\r");
    printf("|       / ) (        |\n\r");
    printf("|_______\(_)/________|\n\r");

    return 0;
}

int display_the_house()
{
    printf("______________________\n\r");
    if(get_zones_active1())
    {
        if(get_zone1())
        {
            display_zone1_safe();
        }
        else
        {
            display_zone1_fire();
        }
    }
    if(get_zones_active2())
    {
        if(get_zone2())
        {
            display_zone2_safe();
        }
        else
        {
            display_zone2_fire();
        }
    }
    if(get_zones_active3())
    {
        if(get_zone3())
        {
            display_zone3_safe();
        }
        else
        {
            display_zone3_fire();
        }
    }

    return 0;
}

int display()
{
    printf("\n\r");

    display_zones_active();

    printf("\n\r");

    display_the_situation();

    printf("\n\r");

    display_the_house();

    printf("\n\r");

	return 0;
}
