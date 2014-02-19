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

int init_alarms();
int init_zone();
int init_zone_active();

int update_zones();
