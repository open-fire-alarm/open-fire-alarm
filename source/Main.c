#include "Init.h"
#include "Display.h"
#include "Options_menu.h"

/* Main.c */

int main()
{
    int stop_main = 0;

    init_all();

    display();

    while(!stop_main)
    {
        options_menu();
    }

	return 0;
}
