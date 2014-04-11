#include "Alarm.h"

/* Extraction.c */

int extraction_port_a(unsigned char interupteurs)
{
	unsigned char tmp = interupteurs;
    tmp = tmp & 0x01;
	set_alarm1(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x02;
	tmp = tmp >> 1;
	set_alarm2(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x04;
	tmp = tmp >> 2;
	set_alarm3(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x08;
	tmp = tmp >> 3;
	set_alarm4(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x10;
	tmp = tmp >> 4;
	set_alarm5(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x20;
	tmp = tmp >> 5;
	set_alarm6(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x40;
	tmp = tmp >> 6;
	set_alarm7(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x80;
	tmp = tmp >> 7;
	set_alarm8(tmp);
	return 0;
}

int extraction_port_e(unsigned char interupteurs)
{
    unsigned char tmp = interupteurs;
    tmp = tmp & 0x01;
	set_alarm9(tmp);
/* if you want stop automatic_loop_microprocessor() with E2 take this code
    tmp = interupteurs;
	tmp = tmp & 0x02;
	tmp = tmp >> 1;
	set_stop_automatic_loop(tmp);
*/

/* if you want change the zones active with switch E3 E4 E5 take this code
	tmp = interupteurs;
	tmp = tmp & 0x04;
	tmp = tmp >> 2;
	set_zones_active1(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x08;
	tmp = tmp >> 3;
	set_zones_active2(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x10;
	tmp = tmp >> 4;
	set_zones_active3(tmp);
*/
    return 0;
}
