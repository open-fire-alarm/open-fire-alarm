#include "Init.h"
#include "Display.h"
#include "Options_menu.h"

int main()
{
    int stop = 0;

    init_all();

    display();

    while(!stop)
    {
        options_menu();
    }

	return 0;
}
