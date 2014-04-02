#include <stdio.h>
#include <time.h>

char *return_time()
{
    time_t t = time(NULL);

    return asctime(localtime(&t));
}

int return_time_microprocessor(char *string_time)
{
    sprintf(string_time,"Time");
    return 0;
}
