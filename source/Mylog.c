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
    strcat(new_line_final,new_line);
    strcat(new_line_final,"\n\r");

    strcat(mylog,new_line_final);
    return 0;
}

int update_mylog_zones_active()
{
    char *new_line="changement des zones actives";
    add_line_to_mylog(new_line);

    return 0;
}

int update_mylog_zones_on_fire()
{
    return 0;
}
int update_mylog_alarms_on_fire()
{
    return 0;
}

int print_mylog()
{
    printf("%s",mylog);

    return  0;
}
