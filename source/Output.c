#include "Alarm.h"

int port_g()
{
    int everything_is_safe = 1;

    unsigned char *portg,*ddrg;
    portg=(unsigned char *)0x02;
    /*Cast values into pointers*/
    ddrg=(unsigned char *)0x03;
    *ddrg=0xff;
    /*Set DDRA to all outputs*/

    if(get_zones_active1())
    {
        if(!(get_alarm1()&&get_alarm2()&&get_alarm3()))
        {
            everything_is_safe = 0;
        }
    }
    if(get_zones_active2())
    {
        if(!(get_alarm4()&&get_alarm5()&&get_alarm6()))
        {
            everything_is_safe = 0;
        }
    }
    if(get_zones_active3())
    {
        if(!(get_alarm7()&&get_alarm8()&&get_alarm9()))
        {
            everything_is_safe = 0;
        }
    }

    if(everything_is_safe) /* everything is safe */
    {
        *portg = 0x00; /* no light */
    }
    else
    {
        *portg = 0x01; /* light */
    }

    return 0;
}
