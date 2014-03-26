#include <stdio.h>
#include"Shell.h"
#include"Display.h"
#include"Input.h"
#include"Alarm.h"
#include"Output.h"

int stop_automatic_loop = 0;

int set_stop_automatic_loop(int new_stop_automatic_loop)
{
    stop_automatic_loop = new_stop_automatic_loop;
    return 0;
}

int return_to_the_menu()
{
    int commande_utilisateur;

    printf("do you want return to the menu?(yes = 1 / no = 0)\n\r");
    scanf("%d",&commande_utilisateur);

    stop_automatic_loop = commande_utilisateur; /* 1 stop the loop and 0 don t stop the loop */

    return 0;
}

int automatic_loop()
{
    while(!stop_automatic_loop)
    {
        activate_zones();
        set_alarms();
        display();
        return_to_the_menu();
    }

	return 0;
}

int automatic_loop_microprocessor()
{
    while(!stop_automatic_loop)
    {
        port_a();
        port_e();
        update_zones();
        port_g();
        display();
    }

	return 0;
}
