#include <stdio.h>
#include <string.h>
#include "MyTime.h"
#include "Alarm.h"

/* Mylog.c */

char mylog[2000]; /* the log */

int init_mylog()
{
    mylog[0]='\0';

    return 0;
}

int add_line_to_mylog(char *new_line) /* add the time and the string in parameter in the log */
{
    char new_line_final[1000]; /* the goal is to create the new line */
    char string_time[1000];
    new_line_final[0]='\0';
    string_time[0]='\0';
    return_time(string_time); /* put the current time on the string */
    strcpy(new_line_final,string_time);
    strcat(new_line_final,"-> ");
    strcat(new_line_final,new_line);
    strcat(new_line_final,"\n\r");
    strcat(new_line_final,"\n\r");

    strcat(mylog,new_line_final); /* add the new line created to the log */
    return 0;
}

int update_mylog_zones_active() /* add a line to the log with the time about which zones are active */
{
    char new_line[1000]; /* the goal is to create the new line */
    new_line[0]='\0';
    if(get_zones_active1() && get_zones_active2() && get_zones_active3())
    {
        strcpy(new_line,"every zones are active");
    }
    if(!get_zones_active1())
    {
        strcat(new_line,"zone 1 inactive, ");
    }
    if(!get_zones_active2())
    {
        strcat(new_line,"zone 2 inactive, ");
    }
    if(!get_zones_active3())
    {
        strcat(new_line,"zone 3 inactive, ");
    }
    add_line_to_mylog(new_line); /* this function add the time and the string in parameter in the log */

    return 0;
}

int update_mylog_zones_on_fire() /* add a line to the log with the time about which zones are on fire */
{
    char new_line[1000]; /* the goal is to create the new line */
    new_line[0]='\0';
    if(get_zone1() && get_zone2() && get_zone3())
    {
        strcpy(new_line,"every zones are safe");
    }
    if(!get_zone1())
    {
        strcat(new_line,"zone 1 on fire, ");
    }
    if(!get_zone2())
    {
        strcat(new_line,"zone 2 on fire, ");
    }
    if(!get_zone3())
    {
        strcat(new_line,"zone 3 on fire, ");
    }
    add_line_to_mylog(new_line); /* this function add the time and the string in parameter in the log */

    return 0;
}
int update_mylog_alarms_on_fire() /* add a line to the log with the time about which alarms are on fire */
{
    char new_line[1000]; /* the goal is to create the new line */
    new_line[0]='\0';
    if(get_alarm1() && get_alarm2() && get_alarm3() && get_alarm4() && get_alarm5() && get_alarm6() && get_alarm7() && get_alarm8() && get_alarm9())
    {
        strcpy(new_line,"no fire");
    }
    if(!get_alarm1())
    {
        strcat(new_line,"alarm1 fire, ");
    }
    if(!get_alarm2())
    {
        strcat(new_line,"alarm2 fire, ");
    }
    if(!get_alarm3())
    {
        strcat(new_line,"alarm3 fire, ");
    }
    if(!get_alarm4())
    {
        strcat(new_line,"alarm4 fire, ");
    }
    if(!get_alarm5())
    {
        strcat(new_line,"alarm5 fire, ");
    }
    if(!get_alarm6())
    {
        strcat(new_line,"alarm6 fire, ");
    }
    if(!get_alarm7())
    {
        strcat(new_line,"alarm7 fire, ");
    }
    if(!get_alarm8())
    {
        strcat(new_line,"alarm8 fire, ");
    }
    if(!get_alarm9())
    {
        strcat(new_line,"alarm9 fire, ");
    }

    add_line_to_mylog(new_line); /* this function add the time and the string in parameter in the log */

    return 0;
}

int print_mylog() /* print the log */
{
    if(mylog[0]=='\0') /* print "no log for the moment" if no log */
    {
        printf("no log for the moment\n\r");
    }
    else
    {
        printf("%s",mylog);
    }

    return  0;
}
