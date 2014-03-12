#include <stdio.h>
#include <string.h>
#include "MyTime.h"

char *mylog;

int my_log_init()
{
    mylog="";

    return 0;
}

int add_line_to_mylog(char *new_line)
{
    new_line=strcat(return_time(),new_line);
    mylog=strcat(mylog,"\n\r");
    mylog=strcat(mylog,new_line);

    return 0;
}

int print_mylog()
{
    printf("%s",mylog);

    return  0;
}
