#include <stdio.h>
#include <time.h>

char *return_time()
{
    time_t t = time(NULL);

    return asctime(localtime(&t));
}
