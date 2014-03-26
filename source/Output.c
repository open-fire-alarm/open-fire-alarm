#include "Alarm.h"

int port_g()
{
    unsigned char *portg,*ddrg;
    portg=(unsigned char *)0x02;
    /*Cast values into pointers*/
    ddrg=(unsigned char *)0x03;
    *ddrg=0xff;
    /*Set DDRA to all outputs*/

    if(get_alarm1() && get_alarm2() && get_alarm3() && get_alarm4() && get_alarm5() && get_alarm6() && get_alarm7() && get_alarm8() && get_alarm9()) /* everything is safe */
    {
        *portg = 0x00;
    }
    else
    {
        *portg = 0x01;
    }

    return 0;
}
