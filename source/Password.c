#include <stdio.h>
#include <string.h>

char password[200];

int init_password()
{
    char new_password[200];
    new_password[0]='\0';
    printf("press the password what you want\n\r");
    scanf("%s",new_password);
	strcpy(password,new_password);
	return 0;
}

int set_password(char *new_password)
{
    strcpy(password,new_password);
    return 0;
}

int test_password(char *try_password)
{
	return strcmp(password,try_password); /* return 0 if it's ok */
}

int change_password()
{
    char old_password[200];
    char new_password[200];
    printf("change password...\n\r");
    printf("press the old password\n\r");
    scanf("%s",old_password);
    if(test_password(old_password)) /* old password bab */
    {
        printf("bad password\n\r");
        return 1;
    }
    printf("press the new password\n\r");
    scanf("%s",new_password);
    printf("press again the new password\n\r");
    scanf("%s",old_password);
    if(strcmp(new_password,old_password)) /* strcmp return 0 if strins are the same */
    {
        printf("it is not the same password\n\r");
        return 1;
    }
    set_password(old_password);
    printf("password change with success\n\r");
    return 0;
}

int request_password()
{
    char old_password[200];
    printf("request password...\n\r");
    printf("press the password\n\r");
    scanf("%s",old_password);
    if(test_password(old_password)) /* old password bab */
    {
        printf("bad password\n\r");
        return 1;
    }
    printf("good password\n\r");
    return 0;
}
