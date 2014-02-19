struct Alarms
{
    int alarm1;
    int alarm2;
    int alarm3;
	int alarm4;
	int alarm5;
	int alarm6;
	int alarm7;
	int alarm8;
	int alarm9;
};

struct Zones
{
	int zone1;
	int zone2;
	int zone3;
};

struct Alarms alarms;
struct Zones zones;

int init_alarms()
{
    alarms.alarm1 = 1;
    alarms.alarm2 = 1;
    alarms.alarm3 = 1;
    alarms.alarm4 = 1;
    alarms.alarm5 = 1;
    alarms.alarm6 = 1;
    alarms.alarm7 = 1;
    alarms.alarm8 = 1;
    alarms.alarm9 = 1;
    return 0;
}

int init_zone()
{
    zones.zone1 = 1;
    zones.zone2 = 1;
    zones.zone3 = 1;
    return 0;
}

int update_zones()
{
	if (alarms.alarm1 == 1 && alarms.alarm2 == 1 && alarms.alarm3 == 1)
	{
		zones.zone1 = 1;
	}
	else
	{
		zones.zone1 = 0;
	}
	if (alarms.alarm4 == 1 && alarms.alarm5 == 1 && alarms.alarm6 == 1)
	{
		zones.zone2 = 1;
	}
	else
	{
		zones.zone2 = 0;
	}
	if (alarms.alarm7 == 1 && alarms.alarm8 == 1 && alarms.alarm9 == 1)
	{
		zones.zone3 = 1;
	}
	else
	{
		zones.zone3 = 0;
	}
	return 0;
}
