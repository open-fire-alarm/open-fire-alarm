#include "Alarm.h"

int extraction(unsigned char interupteurs)
{
	unsigned char tmp = interupteurs;
    tmp = tmp & 0x01;
	alarms.alarm1 = tmp;
    tmp = interupteurs;
	tmp = tmp & 0x02;
	tmp = tmp >> 1;
	alarms.alarm2 = tmp;
    tmp = interupteurs;
	tmp = tmp & 0x04;
	tmp = tmp >> 2;
	alarms.alarm3 = tmp;
    tmp = interupteurs;
	tmp = tmp & 0x08;
	tmp = tmp >> 3;
	alarms.alarm4 = tmp;
    tmp = interupteurs;
	tmp = tmp & 0x10;
	tmp = tmp >> 4;
	alarms.alarm5 = tmp;
    tmp = interupteurs;
	tmp = tmp & 0x20;
	tmp = tmp >> 5;
	alarms.alarm6 = tmp;
    tmp = interupteurs;
	tmp = tmp & 0x40;
	tmp = tmp >> 6;
	alarms.alarm7 = tmp;
    tmp = interupteurs;
	tmp = tmp & 0x80;
	tmp = tmp >> 7;
	alarms.alarm8 = tmp;
    tmp = interupteurs;
	tmp = tmp & 0x01;
	tmp = tmp >> 8;
	alarms.alarm9 = tmp;
	return 0;
}
