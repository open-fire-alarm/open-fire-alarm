#include <stdio.h>
#include"Shell.h"
#include"Display.h"
#include"Input.h"
#include"Alarm.h"
#include"Output.h"
#include"Sleep.h"
#include"Mygetchar.h"

int do_you_want_return_to_the_menu()
{
    int commande_utilisateur;

    printf("do you want return to the menu?(yes = 1 / no = 0)\n\r");
    scanf("%d",&commande_utilisateur);

    return commande_utilisateur; /* 1 stop the loop and 0 don t stop the loop */
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
        port_a();
        port_e();
        update_zones();
        port_g();
        display();
        sleep(1000);
        key = mygetchar();
        if(key != '\0')
        {
            stop_automatic_loop = 1;
        }
    }

	return 0;
}
