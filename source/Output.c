#include "Alarm.h"

int port_g()
{
    unsigned char *portg,*ddrg;
    portg=(unsigned char *)0x02;
    /*Cast values into pointers*/
    ddrg=(unsigned char *)0x03;
    *ddrg=0xff;
    /*Set DDRA to all outputs*/

    /* traitement */
    if(everything_is_safe()) /* everything is safe */
    {
        *portg = 0x00; /* no light */
    }
    else
    {
        *portg = 0x01; /* light */
    }

    return 0;
}
