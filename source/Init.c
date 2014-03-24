#include<stdio.h>
#include"Alarm.h"
#include"Password.h"
#include"Mylog.h"

int init_all()
{
    printf("initialization...\n\r");
	init_alarms();
	init_zone();
	init_zone_active();
	init_password();
    init_mylog();
    printf("finish\n\r");
	return 0;
}
