#include <stdio.h>
#include "Alarm.h"
#include "Mylog.h"

int activate_zones()
{
    int commande_utilisateur;

    printf("zone 1 active = ");
	scanf("%d", &commande_utilisateur);
	set_zones_active1(commande_utilisateur);

    printf("zone 2 active = ");
	scanf("%d", &commande_utilisateur);
	set_zones_active2(commande_utilisateur);

	printf("zone 3 active = ");
	scanf("%d", &commande_utilisateur);
	set_zones_active3(commande_utilisateur);

	update_mylog_zones_active();

    return 0;
}

int activate_alarms ()
{
    int commande_utilisateur;

	printf("alarm 1 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm1(commande_utilisateur);

	printf("alarm 2 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm2(commande_utilisateur);

	printf("alarm 3 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm3(commande_utilisateur);

	printf("alarm 4 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm4(commande_utilisateur);

	printf("alarm 5 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm5(commande_utilisateur);

	printf("alarm 6 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm6(commande_utilisateur);

	printf("alarm 7 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm7(commande_utilisateur);

	printf("alarm 8 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm8(commande_utilisateur);

	printf("alarm 9 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm9(commande_utilisateur);

    update_zones(); /* modifie les valeurs des zones automatiquement quand on change les valeurs des alarms */

    update_mylog_zones_on_fire();
    update_mylog_alarms_on_fire();

	return 0;
}
