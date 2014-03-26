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
struct Zones zones_active;

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

int init_zone_active()
{
    zones_active.zone1 = 0;
    zones_active.zone2 = 0;
    zones_active.zone3 = 0;
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

int get_alarm1()
{
    return alarms.alarm1;
}

int set_alarm1(int new_alarm1)
{
    alarms.alarm1=new_alarm1;
    return 0;
}

int get_alarm2()
{
    return alarms.alarm2;
}

int set_alarm2(int new_alarm2)
{
    alarms.alarm2=new_alarm2;
    return 0;
}

int get_alarm3()
{
    return alarms.alarm3;
}

int set_alarm3(int new_alarm3)
{
    alarms.alarm3=new_alarm3;
    return 0;
}

int get_alarm4()
{
    return alarms.alarm4;
}

int set_alarm4(int new_alarm4)
{
    alarms.alarm4=new_alarm4;
    return 0;
}

int get_alarm5()
{
    return alarms.alarm5;
}

int set_alarm5(int new_alarm5)
{
    alarms.alarm5=new_alarm5;
    return 0;
}

int get_alarm6()
{
    return alarms.alarm6;
}

int set_alarm6(int new_alarm6)
{
    alarms.alarm6=new_alarm6;
    return 0;
}

int get_alarm7()
{
    return alarms.alarm7;
}

int set_alarm7(int new_alarm7)
{
    alarms.alarm7=new_alarm7;
    return 0;
}

int get_alarm8()
{
    return alarms.alarm8;
}

int set_alarm8(int new_alarm8)
{
    alarms.alarm8=new_alarm8;
    return 0;
}

int get_alarm9()
{
    return alarms.alarm9;
}

int set_alarm9(int new_alarm9)
{
    alarms.alarm9=new_alarm9;
    return 0;
}

int get_zone1()
{
    return zones.zone1;
}

int get_zone2()
{
    return zones.zone2;
}

int get_zone3()
{
    return zones.zone3;
}

int get_zones_active1()
{
    return zones_active.zone1;
}

int set_zones_active1(int new_zones_active1)
{
    zones_active.zone1=new_zones_active1;
    return 0;
}

int get_zones_active2()
{
    return zones_active.zone2;
}

int set_zones_active2(int new_zones_active2)
{
    zones_active.zone2=new_zones_active2;
    return 0;
}

int get_zones_active3()
{
    return zones_active.zone3;
}

int set_zones_active3(int new_zones_active3)
{
    zones_active.zone3=new_zones_active3;
    return 0;
}

int everything_is_safe()
{
    int safe = 1;
    if(zones_active.zone1)
    {
        if(!(alarms.alarm1 && alarms.alarm2 && alarms.alarm3))
        {
            safe = 0;
        }
    }
    if(zones_active.zone2)
    {
        if(!(alarms.alarm4 && alarms.alarm5 && alarms.alarm6))
        {
            safe = 0;
        }
    }
    if(zones_active.zone3)
    {
        if(!(alarms.alarm7 && alarms.alarm8 && alarms.alarm9))
        {
            safe = 0;
        }
    }
    return safe;
}
