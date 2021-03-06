#include <stdio.h>
#include "Alarm.h"
#include "Mylog.h"

/* Shell.c */

int activate_zones()
{
    int commande_utilisateur;

    do
    {
        printf("zone 1 active = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1)); /* check the user command and ask again if it is not correct */
	set_zones_active1(commande_utilisateur);

    do
    {
        printf("zone 2 active = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_zones_active2(commande_utilisateur);

    do
    {
        printf("zone 3 active = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_zones_active3(commande_utilisateur);

	update_mylog_zones_active(); /* add a line to the log with the time about which zones are active */

    return 0;
}

int set_alarms ()
{
    int commande_utilisateur;

    do
    {
        printf("alarm 1 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1)); /* check the user command and ask again if it is not correct */
	set_alarm1(commande_utilisateur);

    do
    {
        printf("alarm 2 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm2(commande_utilisateur);

    do
    {
        printf("alarm 3 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm3(commande_utilisateur);

    do
    {
        printf("alarm 4 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm4(commande_utilisateur);

    do
    {
        printf("alarm 5 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm5(commande_utilisateur);

    do
    {
        printf("alarm 6 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm6(commande_utilisateur);

    do
    {
        printf("alarm 7 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm7(commande_utilisateur);

	printf("alarm 8 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm8(commande_utilisateur);

    do
    {
        printf("alarm 9 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm9(commande_utilisateur);

    update_zones(); /* values of zones are changed automatically with alarms values */

    update_mylog_zones_on_fire(); /* add a line to the log with the time about which zones are on fire */
    update_mylog_alarms_on_fire(); /* add a line to the log with the time about which alarms are on fire */

	return 0;
}
