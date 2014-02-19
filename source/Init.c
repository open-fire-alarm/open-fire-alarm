#include<stdio.h>
#include"Alarm.h"
#include"Password.h"

int init_all()
{
    printf("initialization...\n\r");
	init_alarms();
	init_zone();
	init_zone_active();
	init_password();
	return 0;
}
