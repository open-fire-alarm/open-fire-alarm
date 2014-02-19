#include <stdio.h>
#include "Password.h"
#include "Shell.h"
#include "Display.h"
#include "Init.h"

int options_menu()
{
    int commande_utilisateur;
    printf("Welcome to the options menu\n\r");
    printf("Press 1 to change the password\n\r");
    printf("Press 2 to activate zones\n\r");
    printf("Press 3 to activate alarms\n\r");
    printf("Press 4 to display\n\r");
    printf("Press 5 to launch the alarm system\n\r");
    printf("Press 6 to reset all\n\r");
    scanf("%d",&commande_utilisateur);

    if(commande_utilisateur == 1)
    {
        /* change the password */
        change_password();
    }
    if(commande_utilisateur == 2)
    {
        /* activate zones */
        activate_zones();
    }
    if(commande_utilisateur == 3)
    {
        /* activate alarms */
        activate_alarms();
    }
    if(commande_utilisateur == 4)
    {
        /* display */
        display();
    }
    if(commande_utilisateur == 5)
    {
        /* launch the alarm system */
    }
    if(commande_utilisateur == 6)
    {
        /* reset */
        init_all();
    }

    return 0;
}
