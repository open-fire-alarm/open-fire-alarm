#include <stdio.h>
#include "Password.h"
#include "Shell.h"
#include "Display.h"
#include "Automatic_loop.h"
#include "Init.h"
#include "Mylog.h"
#include "Help.h"

/* Options_menu.c */

int options_menu() /* launch the menu */
{
    int commande_utilisateur;

    printf("\n\r");

    printf("Welcome to the options menu\n\r");
    printf("Press 1 to change the password\n\r");
    printf("Press 2 to activate zones\n\r");
    printf("Press 3 to set alarms\n\r");
    printf("Press 4 to display\n\r");
    printf("Press 5 to launch the alarm system\n\r");
    printf("Press 6 to print the log\n\r");
    printf("Press 7 to reset all\n\r");
    printf("Press 8 to have help\n\r");
    scanf("%d",&commande_utilisateur);

    if(commande_utilisateur == 1)
    {
        /* change the password */
        change_password();
        return 0;
    }
    if(commande_utilisateur == 2)
    {
        /* activate zones */
        activate_zones();
        return 0;
    }
    if(commande_utilisateur == 3)
    {
        /* set alarms */
        set_alarms();
        return 0;
    }
    if(commande_utilisateur == 4)
    {
        /* display */
        display();
        return 0;
    }
    if(commande_utilisateur == 5)
    {
        /* launch the alarm system */
        automatic_loop();
        return 0;
    }
    if(commande_utilisateur == 6)
    {
        /* print the log */
        print_mylog();
        return 0;
    }
    if(commande_utilisateur == 7)
    {
        /* reset */
        init_all();
        return 0;
    }
    if(commande_utilisateur == 8)
    {
        /* help */
        print_help();
        return 0;
    }

    return 1;
}
