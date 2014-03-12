#include <time.h>

const struct tm* tmptr;

char *return_time()
{
    return asctime(tmptr);
}
