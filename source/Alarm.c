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
    alarms.alarm1 = 0;
    alarms.alarm2 = 0;
    alarms.alarm3 = 0;
    alarms.alarm4 = 0;
    alarms.alarm5 = 0;
    alarms.alarm6 = 0;
    alarms.alarm7 = 0;
    alarms.alarm8 = 0;
    alarms.alarm9 = 0;
    return 0;
}

int init_zone()
{
    zones.zone1 = 0;
    zones.zone2 = 0;
    zones.zone3 = 0;
    return 0;
}

int update_zones()
{
	if (alarms.alarm1 == 0 && alarms.alarm2 == 0 && alarms.alarm3 == 0)
	{
		zones.zone1 = 0;
	}
	else
	{
		zones.zone1 = 1;
	}
	if (alarms.alarm4 == 0 && alarms.alarm5 == 0 && alarms.alarm6 == 0)
	{
		zones.zone2 = 0;
	}
	else
	{
		zones.zone2 = 1;
	}
	if (alarms.alarm7 == 0 && alarms.alarm8 == 0 && alarms.alarm9 == 0)
	{
		zones.zone3 = 0;
	}
	else
	{
		zones.zone3 = 1;
	}
	return 0;
}
