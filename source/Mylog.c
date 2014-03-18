#include <stdio.h>
#include <string.h>
#include "MyTime.h"
#include "Alarm.h"

char mylog[1000];

int init_mylog()
{
    mylog[0]='\0';

    return 0;
}

int add_line_to_mylog(char *new_line)
{
    char new_line_final[500];
    new_line_final[0]='\0';
    char string_time[100];
    string_time[0]='\0';
    strcpy(string_time,return_time());
    strcpy(new_line_final,string_time);
    strcat(new_line_final,"-> ");
    strcat(new_line_final,new_line);
    strcat(new_line_final,"\n\r");
    strcat(new_line_final,"\n\r");

    strcat(mylog,new_line_final);
    return 0;
}

int update_mylog_zones_active()
{
    char new_line[200];
    new_line[0]='\0';
    if(zones_active.zone1 && zones_active.zone2 && zones_active.zone3)
    {
        strcpy(new_line,"every zones are active");
    }
    if(!zones_active.zone1)
    {
        strcat(new_line,"zone 1 inactive, ");
    }
    if(!zones_active.zone2)
    {
        strcat(new_line,"zone 2 inactive, ");
    }
    if(!zones_active.zone3)
    {
        strcat(new_line,"zone 3 inactive, ");
    }
    add_line_to_mylog(new_line);

    return 0;
}

int update_mylog_zones_on_fire()
{
    char new_line[200];
    new_line[0]='\0';
    if(zones.zone1 && zones.zone2 && zones.zone3)
    {
        strcpy(new_line,"every zones are safe");
    }
    if(!zones.zone1)
    {
        strcat(new_line,"zone 1 on fire, ");
    }
    if(!zones.zone2)
    {
        strcat(new_line,"zone 2 on fire, ");
    }
    if(!zones.zone3)
    {
        strcat(new_line,"zone 3 on fire, ");
    }
    add_line_to_mylog(new_line);

    return 0;
}
int update_mylog_alarms_on_fire()
{
    char new_line[200];
    new_line[0]='\0';
    if(alarms.alarm1 && alarms.alarm2 && alarms.alarm3 && alarms.alarm4 && alarms.alarm5 && alarms.alarm6 && alarms.alarm7 && alarms.alarm8 && alarms.alarm9)
    {
        strcpy(new_line,"no fire");
    }
    if(!alarms.alarm1)
    {
        strcat(new_line,"alarm1 fire, ");
    }
    if(!alarms.alarm2)
    {
        strcat(new_line,"alarm2 fire, ");
    }
    if(!alarms.alarm3)
    {
        strcat(new_line,"alarm3 fire, ");
    }
    if(!alarms.alarm4)
    {
        strcat(new_line,"alarm4 fire, ");
    }
    if(!alarms.alarm5)
    {
        strcat(new_line,"alarm5 fire, ");
    }
    if(!alarms.alarm6)
    {
        strcat(new_line,"alarm6 fire, ");
    }
    if(!alarms.alarm7)
    {
        strcat(new_line,"alarm7 fire, ");
    }
    if(!alarms.alarm8)
    {
        strcat(new_line,"alarm8 fire, ");
    }
    if(!alarms.alarm9)
    {
        strcat(new_line,"alarm9 fire, ");
    }

    add_line_to_mylog(new_line);

    return 0;
}

int print_mylog()
{
    if(mylog[0]=='\0')
    {
        printf("no log for the moment\n\r");
    }
    else
    {
        printf("%s",mylog);
    }

    return  0;
}
