#include "Init.h"
#include "Display.h"
#include "Options_menu.h"

/* Main.c */

int main()
{
    int stop_main = 0;

    init_all(); /* initialize everything */

    display(); /* display informations about the alarms and zones */

    while(!stop_main) /* never stop */
    {
        options_menu(); /* launch the menu */
    }

	return 0;
}
