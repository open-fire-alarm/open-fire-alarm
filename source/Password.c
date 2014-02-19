#include <string.h>

char password[20];

int init_password()
{
	strcpy(password,"00000");
	return 0;
}

int test_password(char *try_password)
{
	return strcmp(password,try_password); /* return 0 if it's ok */
}
