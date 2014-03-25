#include"Shell.h"
#include"Display.h"

int automatic_loop()
{
    int stop = 0;

    while(!stop)
    {
        activate_zones();
        activate_alarms();
        display();
    }

	return 0;
}
