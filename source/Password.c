#include <stdio.h>
#include <string.h>

/* Password.c */

char password[200]; /* the password */

int init_password() /* initialize the password */
{
    char new_password[200];
    new_password[0]='\0';
    printf("press the password what you want\n\r");
    scanf("%s",new_password); /* ask what is the password for the initialization */
	strcpy(password,new_password);
	return 0;
}

int set_password(char *new_password) /* change the password */
{
    strcpy(password,new_password);
    return 0;
}

int test_password(char *try_password) /* test if the parameter is the same of the password */
{
	return strcmp(password,try_password); /* return 0 if it's ok */
}

int change_password() /* launch the procedure for changing the password */
{
    char old_password[200];
    char new_password[200];
    printf("change password...\n\r");
    printf("press the old password\n\r");
    scanf("%s",old_password);
    if(test_password(old_password)) /* if old password bab then */
    {
        printf("bad password\n\r");
        return 1; /* stop */
    }
    printf("press the new password\n\r");
    scanf("%s",new_password);
    printf("press again the new password\n\r");
    scanf("%s",old_password);
    if(strcmp(new_password,old_password)) /* strcmp return 0 if strins are the same */
    {
        printf("it is not the same password\n\r");
        return 1; /* stop */
    }
    set_password(old_password); /* change the password */
    printf("password change with success\n\r");
    return 0;
}

int request_password() /* ask the password to the user, if bad password return 1 else return 0 */
{
    char old_password[200];
    printf("request password...\n\r");
    printf("press the password\n\r");
    scanf("%s",old_password);
    if(test_password(old_password)) /* test if the parameter is the same of the password, return 0 if it's good */
    {
        printf("bad password\n\r");
        return 1; /* stop */
    }
    printf("good password\n\r");
    return 0;
}
