#include <stdio.h>
#include"Shell.h"
#include"Display.h"
#include"Input.h"
#include"Alarm.h"
#include"Output.h"
#include"Sleep.h"
#include"Mygetchar.h"

/* Automatic_loop.c */

int do_you_want_return_to_the_menu()
{
    int commande_utilisateur;

    printf("do you want return to the menu?(yes = 1 / no = 0)\n\r");
    scanf("%d",&commande_utilisateur);

    return commande_utilisateur; /* 1 the user want to stop the loop and 0 the user don t want to stop the loop */
}

int automatic_loop()
{
    int stop_automatic_loop = 0;

    while(!stop_automatic_loop)
    {
        /* if you want activate zones in this mod
        activate_zones();
        */
        set_alarms();
        display();
        stop_automatic_loop = do_you_want_return_to_the_menu(); /* 1 stop the loop and 0 don t stop the loop */
    }

	return 0;
}

int automatic_loop_microprocessor()
{
    int stop_automatic_loop = 0;
    unsigned char key;

    while(!stop_automatic_loop)
    {
        port_a(); /* take the information of port a, extract it and change values of alarms */
        port_e(); /* take the information of port e, extract it and change values of alarms */
        update_zones(); /* update zones values */
        port_g(); /* change the value of port g for turn on or turn off the light (depending to the alarms value) */
        display(); /* display informations about the alarms and zones */
        sleep(1000); /* a little break */
        key = mygetchar(); /* take a key if the user press the keyboard */
        if(key != '\0') /* if the keyboard is press then stop the loop */
        {
            stop_automatic_loop = 1;
        }
    }

	return 0;
}
