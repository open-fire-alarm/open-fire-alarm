#include <stdio.h>
#include "Alarm.h"

int set_utilisateur_alarms ()
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

	return 0;
}
