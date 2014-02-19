#include "Alarm.h"
#include "Shell.h"
#include "Display.h"
#include "Password.h"

int main()
{
    int stop = 0;

	init_alarms();
	init_zone();
	init_password();

    display();

	while (!stop)
	{
        commande_utilisateur();
        update_zones();
        display();
	}
	return 0;
}
