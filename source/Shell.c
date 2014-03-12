#include <stdio.h>
#include "Alarm.h"
#include "Mylog.h"

int activate_zones()
{
    printf("zone 1 active = ");
	scanf("%d", &zones_active.zone1);

    printf("zone 2 active = ");
	scanf("%d", &zones_active.zone2);

	printf("zone 3 active = ");
	scanf("%d", &zones_active.zone3);

	update_mylog_zones_active();

    return 0;
}

int activate_alarms ()
{
	printf("alarm 1 = ");
	scanf("%d", &alarms.alarm1);

    printf("alarm 2 = ");
	scanf("%d", &alarms.alarm2);

	printf("alarm 3 = ");
	scanf("%d", &alarms.alarm3);

	printf("alarm 4 = ");
	scanf("%d", &alarms.alarm4);

	printf("alarm 5 = ");
	scanf("%d", &alarms.alarm5);

	printf("alarm 6 = ");
	scanf("%d", &alarms.alarm6);

	printf("alarm 7 = ");
	scanf("%d", &alarms.alarm7);

	printf("alarm 8 = ");
	scanf("%d", &alarms.alarm8);

	printf("alarm 9 = ");
	scanf("%d", &alarms.alarm9);

    update_zones(); /* modifie les valeurs des zones automatiquement quand on change les valeurs des alarms */

    update_mylog_zones_on_fire();
    update_mylog_alarms_on_fire();

	return 0;
}
