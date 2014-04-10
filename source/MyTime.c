#include <stdio.h>
#include <string.h>
#include <time.h>

int return_time(char *string_time)
{
    time_t t = time(NULL);

    strcpy(string_time,asctime(localtime(&t)));

    return 0;
}

int return_time_microprocessor(char *string_time)
{
    sprintf(string_time,"Time");
    return 0;
}
