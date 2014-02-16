#include "Alarm.h"
#include "Shell.h"
#include "Display.h"

int main()
{
    int stop = 0;

    init_alarms();
    init_zone();
    display();

	while (!stop)
	{
        commande_utilisateur();
        update_zones();
        display();
	}
	return 0;
}
