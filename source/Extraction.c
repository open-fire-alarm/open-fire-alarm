#include "Alarm.h"

int extraction(unsigned char commande_utilisateur)
{
	unsigned char tmp = commande_utilisateur;
	tmp = tmp & 0x01;
	alarms.alarm1 = tmp;
	alarms.alarm2 = tmp;
	alarms.alarm3 = tmp;
	alarms.alarm4 = tmp;
	alarms.alarm5 = tmp;
	alarms.alarm6 = tmp;
	alarms.alarm7 = tmp;
	alarms.alarm8 = tmp;
	alarms.alarm9 = tmp;
	return 0;
}