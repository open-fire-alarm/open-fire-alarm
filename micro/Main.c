#include <stdio.h>
#include <string.h>

/* Options_menu.h */

int options_menu(); /* launch the menu */

/* Help.h */

int print_help(); /* print help message */

/* Automatic_loop.h */

int automatic_loop(); /* launch the automatic loop (everything is automatic you should press a key to return to the menu) */

int automatic_loop_microprocessor(); /* for the microprocessor you should replace automatic_loop() by automatic_loop_microprocessor() */

/* Init.h */

int init_all(); /* initialize everything (or reset everything) */

/* Display.h */

int display(); /* display informations about the alarms and zones */

/* Input.h */

int port_a(); /* take the information of port a and give it to extraction_port_a(information_of_port_a) in Extraction.h */

int port_e(); /* take the information of port e and give it to extraction_port_e(information_of_port_e) in Extraction.h */

/* Mygetchar.h */

unsigned char mygetchar(); /* a version of getchar but no wait the user, if the user press a key mygetchar return the key else mygetchar return \0 */

/* Sleep.h */

int sleep(int limit); /* a function to do a little break */

/* Shell.h */

int activate_zones(); /* a function ask to the user which zones are activated */

int set_alarms (); /* a function which simulate sensor for the visual studio program and ask to the user what are the values for the alarms */

/* Password.h */

int init_password(); /* initialize the password */

int change_password(); /* launch the procedure for changing the password */

int request_password(); /* ask the password to the user, if bad password return 1 else return 0 */

/* Extraction.h */

int extraction_port_a(unsigned char interupteurs); /* extract all informations of port a and change values of alarms */

int extraction_port_e(unsigned char interupteurs); /* extract all informations of port e and change values of alarms */

/* Output.h */

int port_g(); /* change the value of port g automatically with alarms values to turn on or off the light */

/* Mylog.h */

int init_mylog(); /* initialization of the log */

int update_mylog_zones_active(); /* add a line to the log with the time about which zones are active */

int update_mylog_zones_on_fire(); /* add a line to the log with the time about which zones are on fire */

int update_mylog_alarms_on_fire(); /* add a line to the log with the time about which alarms are on fire */

int print_mylog(); /* print the log */

/* Alarm.h */

int init_alarms(); /* initialization of alarms (all are safe) */
int init_zone(); /* initialization of zone (all are safe) */
int init_zone_active(); /* initialization of which zones are active (all are deactivated) */

int update_zones(); /* values of zones are changed automatically with alarms values */

int get_alarm1(); /* have the value of alarm1 */
int set_alarm1(int new_alarm1); /* change the value of alarm1 */
int get_alarm2(); /* have the value of alarm2 */
int set_alarm2(int new_alarm2); /* change the value of alarm2 */
int get_alarm3(); /* have the value of alarm3 */
int set_alarm3(int new_alarm3); /* change the value of alarm3 */
int get_alarm4(); /* have the value of alarm4 */
int set_alarm4(int new_alarm4); /* change the value of alarm4 */
int get_alarm5(); /* have the value of alarm5 */
int set_alarm5(int new_alarm5); /* change the value of alarm5 */
int get_alarm6(); /* have the value of alarm6 */
int set_alarm6(int new_alarm6); /* change the value of alarm6 */
int get_alarm7(); /* have the value of alarm7 */
int set_alarm7(int new_alarm7); /* change the value of alarm7 */
int get_alarm8(); /* have the value of alarm8 */
int set_alarm8(int new_alarm8); /* change the value of alarm8 */
int get_alarm9(); /* have the value of alarm9 */
int set_alarm9(int new_alarm9); /* change the value of alarm9 */

int get_zone1(); /* have the value of zone1 */
int get_zone2(); /* have the value of zone2 */
int get_zone3(); /* have the value of zone3 */

int get_zones_active1(); /* have the value of zones active1 */
int set_zones_active1(int new_zones_active1); /* change the value of zones active1 */
int get_zones_active2(); /* have the value of zones active2 */
int set_zones_active2(int new_zones_active2); /* change the value of zones active2 */
int get_zones_active3(); /* have the value of zones active3 */
int set_zones_active3(int new_zones_active3); /* change the value of zones active3 */

int everything_is_safe(); /* return 1 if everything is safe (no fire) else 0 */

/* MyTime.h */

int return_time_microprocessor(char *string_time); /* for the microprocessor you should replace return_time(char *string_time) by return_time_microprocessor(char *string_time) */

/* Main.c */

int hours,mins,secs,ticks;

int main()
{
    unsigned char *pactl,*tmsk2;
    int stop_main = 0;

	tmsk2=(unsigned char*)0x24;
	pactl=(unsigned char*)0x26;

	*pactl=0x03; /*Set prescaler to maximum*/
	*tmsk2=0x40; /*Enable RTI interrupt*/

    init_all(); /* initialize everything */

    display(); /* display informations about the alarms and zones */

    while(!stop_main) /* never stop */
    {
        options_menu(); /* launch the menu */
    }

	return 0;
}

@interrupt void timer(void)
{
    unsigned char *tflg2;
    tflg2=(unsigned char*)0x25;

	ticks++;
	if (ticks==30)
	{
		ticks=0;
		secs++;
	}
	if (secs==60)
	{
		secs=0;
		mins++;
	}
	if (mins==60)
	{
		mins=0;
		hours++;
	}
	if (hours==24)
	{
		hours=0;
	}
	*tflg2=0x40; /*Reset RTI flag*/
}

/* Options_menu.c */

int options_menu() /* launch the menu */
{
    int commande_utilisateur;

    printf("\n\r");

    printf("Welcome to the options menu\n\r");
    printf("Press 1 to change the password\n\r");
    printf("Press 2 to activate zones\n\r");
    printf("Press 3 to set alarms\n\r");
    printf("Press 4 to display\n\r");
    printf("Press 5 to launch the alarm system\n\r");
    printf("Press 6 to print the log\n\r");
    printf("Press 7 to reset all\n\r");
    printf("Press 8 to have help\n\r");
    scanf("%d",&commande_utilisateur);

    if(commande_utilisateur == 1)
    {
        /* change the password */
        change_password();
        return 0;
    }
    if(commande_utilisateur == 2)
    {
        /* activate zones */
        activate_zones();
        return 0;
    }
    if(commande_utilisateur == 3)
    {
        /* set alarms */
        set_alarms();
        return 0;
    }
    if(commande_utilisateur == 4)
    {
        /* display */
        display();
        return 0;
    }
    if(commande_utilisateur == 5)
    {
        /* launch the alarm system */
        automatic_loop_microprocessor();
        return 0;
    }
    if(commande_utilisateur == 6)
    {
        /* print the log */
        print_mylog();
        return 0;
    }
    if(commande_utilisateur == 7)
    {
        /* reset */
        init_all();
        return 0;
    }
    if(commande_utilisateur == 8)
    {
        /* help */
        print_help();
        return 0;
    }

    return 1;
}

/* Help.c */

int print_help()
{
    printf("Alarms are safe when alarm1 = 1 and on fire when alarm1 = 0 for example.\n\r");
    printf("Zones are activated when zone1 = 1 and deactivated when zone1 = 0 for example.\n\r");
    printf("In port a you have the eight alarms, the last alarm is on port e and the light on port g.\n\r");
    return 0;
}

/* Automatic_loop.c */

int do_you_want_return_to_the_menu()
{
    int commande_utilisateur;

    printf("do you want return to the menu?(yes = 1 / no = 0)\n\r");
    scanf("%d",&commande_utilisateur);

    return commande_utilisateur; /* 1 the user want to stop the loop and 0 the user don t want to stop the loop */
}

int automatic_loop()
{
    int stop_automatic_loop = 0;

    while(!stop_automatic_loop)
    {
        /* if you want activate zones in this mod
        activate_zones();
        */
        set_alarms();
        display();
        stop_automatic_loop = do_you_want_return_to_the_menu(); /* 1 stop the loop and 0 don t stop the loop */
    }

	return 0;
}

int automatic_loop_microprocessor()
{
    int stop_automatic_loop = 0;
    unsigned char key;

    while(!stop_automatic_loop)
    {
        port_a(); /* take the information of port a, extract it and change values of alarms */
        port_e(); /* take the information of port e, extract it and change values of alarms */
        update_zones(); /* update zones values */
        port_g(); /* change the value of port g for turn on or turn off the light (depending to the alarms value) */
        display(); /* display informations about the alarms and zones */
        sleep(1000); /* a little break */
        key = mygetchar(); /* take a key if the user press the keyboard */
        if(key != '\0') /* if the keyboard is press then stop the loop */
        {
            stop_automatic_loop = 1;
        }
    }

	return 0;
}

/* Init.c */

int init_all()
{
    printf("initialization...\n\r");

	init_alarms();
	init_zone();
	init_zone_active();
	init_password();
    init_mylog();

    printf("finish\n\r");

	return 0;
}

/* Display.c */

int display_zones_active()
{
    if(get_zones_active1())
    {
        printf("zones 1 active\n\r");
    }
    else
    {
        printf("zones 1 desactive\n\r");
    }
    if(get_zones_active2())
    {
        printf("zones 2 active\n\r");
    }
    else
    {
        printf("zones 2 desactive\n\r");
    }
    if(get_zones_active3())
    {
        printf("zones 3 active\n\r");
    }
    else
    {
        printf("zones 3 desactive\n\r");
    }

    return 0;
}

int display_alarms_in_zone(int zone)
{
    if(zone==1)
    {
        printf("    alarm 1 = %d\n\r",get_alarm1());
        printf("    alarm 2 = %d\n\r",get_alarm2());
        printf("    alarm 3 = %d\n\r",get_alarm3());
    }
    if(zone==2)
    {
        printf("    alarm 4 = %d\n\r",get_alarm4());
        printf("    alarm 5 = %d\n\r",get_alarm5());
        printf("    alarm 6 = %d\n\r",get_alarm6());
    }
    if(zone==3)
    {
        printf("    alarm 7 = %d\n\r",get_alarm7());
        printf("    alarm 8 = %d\n\r",get_alarm8());
        printf("    alarm 9 = %d\n\r",get_alarm9());
    }
    return 0;
}

int display_the_situation()
{
    if(get_zones_active1())
    {
        if(get_zone1()) /* if zone n safe then print "zone n safe" else print zone n on fire and print all the alarms in the zone n */
        {
            printf("zone 1 safe\n\r");
        }
        else
        {
            printf("zone 1 on fire\n\r");
            display_alarms_in_zone(1);
        }
    }
    if(get_zones_active2())
    {
        if(get_zone2())
        {
            printf("zone 2 safe\n\r");
        }
        else
        {
            printf("zone 2 on fire\n\r");
            display_alarms_in_zone(2);
        }
    }
    if(get_zones_active3())
    {
        if(get_zone3())
        {
            printf("zone 3 safe\n\r");
        }
        else
        {
            printf("zone 3 on fire\n\r");
            display_alarms_in_zone(3);
        }
    }

    return 0;
}

int display_zone1_safe()
{
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|____________________|\n\r");

    return 0;
}

int display_zone1_fire()
{
    printf("|                    |\n\r");
    printf("|         )          |\n\r");
    printf("|        ) |          |\n\r");
    printf("|       / ) (        |\n\r");
    printf("|_______\(_)/________|\n\r");

    return 0;
}

int display_zone2_safe()
{
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|____________________|\n\r");

    return 0;
}

int display_zone2_fire()
{
    printf("|                    |\n\r");
    printf("|         )          |\n\r");
    printf("|        ) |         |\n\r");
    printf("|       / ) (        |\n\r");
    printf("|_______\(_)/________|\n\r");

    return 0;
}

int display_zone3_safe()
{
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|                    |\n\r");
    printf("|____________________|\n\r");

    return 0;
}

int display_zone3_fire()
{
    printf("|                    |\n\r");
    printf("|         )          |\n\r");
    printf("|        ) |         |\n\r");
    printf("|       / ) (        |\n\r");
    printf("|_______\(_)/________|\n\r");

    return 0;
}

int display_the_house()
{
    printf("______________________\n\r");
    if(get_zones_active1())
    {
        if(get_zone1())
        {
            display_zone1_safe();
        }
        else
        {
            display_zone1_fire();
        }
    }
    if(get_zones_active2())
    {
        if(get_zone2())
        {
            display_zone2_safe();
        }
        else
        {
            display_zone2_fire();
        }
    }
    if(get_zones_active3())
    {
        if(get_zone3())
        {
            display_zone3_safe();
        }
        else
        {
            display_zone3_fire();
        }
    }

    return 0;
}

int display()
{
    printf("\n\r");

    display_zones_active();

    printf("\n\r");

    display_the_situation();

    printf("\n\r");

    display_the_house();

    printf("\n\r");

	return 0;
}

/* Input.c */

int port_a()
{
    unsigned char *porta,*ddra;
    porta=(unsigned char *)0x00;
    /*Cast values into pointers*/
    ddra=(unsigned char *)0x01;
    *ddra=0x00;
    /*Set DDRA to all inputs*/

    extraction_port_a(*porta); /* extract all informations of port a and change values of alarms */

    return 0;
}

int port_e()
{
    unsigned char *porte;
    porte=(unsigned char *)0x0a;
    /*Cast values into pointers*/
    extraction_port_e(*porte); /* extract all informations of port e and change values of alarms */

    return 0;
}

/* Mygetchar.c */

unsigned char mygetchar()
{
    unsigned char key;

    unsigned char *scsr, *scdr;

    scsr =(unsigned char *)0x2e;
    scdr = (unsigned char *)0x2f;

    if(*scsr & 0x20) /* masking, if != 0 then return *scdr else return \0 */
    {
        key = *scdr;
    }
    else
    {
        key = '\0';
    }

    return key; /* if a key is press then return the key press else return \0 */
}

/* Sleep.c */

int sleep(int limit)
{
    int compteur = 0;
    while(compteur < limit)
    {
        compteur++;
    }
    return 0;
}

/* Shell.c */

int activate_zones()
{
    int commande_utilisateur;

    do
    {
        printf("zone 1 active = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1)); /* check the user command and ask again if it is not correct */
	set_zones_active1(commande_utilisateur);

    do
    {
        printf("zone 2 active = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_zones_active2(commande_utilisateur);

    do
    {
        printf("zone 3 active = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_zones_active3(commande_utilisateur);

	update_mylog_zones_active(); /* add a line to the log with the time about which zones are active */

    return 0;
}

int set_alarms ()
{
    int commande_utilisateur;

    do
    {
        printf("alarm 1 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1)); /* check the user command and ask again if it is not correct */
	set_alarm1(commande_utilisateur);

    do
    {
        printf("alarm 2 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm2(commande_utilisateur);

    do
    {
        printf("alarm 3 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm3(commande_utilisateur);

    do
    {
        printf("alarm 4 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm4(commande_utilisateur);

    do
    {
        printf("alarm 5 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm5(commande_utilisateur);

    do
    {
        printf("alarm 6 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm6(commande_utilisateur);

    do
    {
        printf("alarm 7 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm7(commande_utilisateur);

	printf("alarm 8 = ");
	scanf("%d", &commande_utilisateur);
	set_alarm8(commande_utilisateur);

    do
    {
        printf("alarm 9 = ");
        scanf("%d", &commande_utilisateur);
    } while(!(commande_utilisateur==0 || commande_utilisateur==1));
	set_alarm9(commande_utilisateur);

    update_zones(); /* values of zones are changed automatically with alarms values */

    update_mylog_zones_on_fire(); /* add a line to the log with the time about which zones are on fire */
    update_mylog_alarms_on_fire(); /* add a line to the log with the time about which alarms are on fire */

	return 0;
}

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

/* Extraction.c */

int extraction_port_a(unsigned char interupteurs)
{
	unsigned char tmp = interupteurs;
    tmp = tmp & 0x01; /* extract the n bit with a mask */
	set_alarm1(tmp); /* change the value of alarm n */
    tmp = interupteurs;
	tmp = tmp & 0x02;
	tmp = tmp >> 1; /* after extract the n bit with a mask you should shift the bit to the fist place */
	set_alarm2(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x04;
	tmp = tmp >> 2;
	set_alarm3(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x08;
	tmp = tmp >> 3;
	set_alarm4(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x10;
	tmp = tmp >> 4;
	set_alarm5(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x20;
	tmp = tmp >> 5;
	set_alarm6(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x40;
	tmp = tmp >> 6;
	set_alarm7(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x80;
	tmp = tmp >> 7;
	set_alarm8(tmp);
	return 0;
}

int extraction_port_e(unsigned char interupteurs)
{
    unsigned char tmp = interupteurs;
    tmp = tmp & 0x01; /* extract the n bit with a mask */
	set_alarm9(tmp); /* change the value of alarm n */
/* if you want stop automatic_loop_microprocessor() with E2 take this code
    tmp = interupteurs;
	tmp = tmp & 0x02;
	tmp = tmp >> 1;
	set_stop_automatic_loop(tmp);
*/

/* if you want change the zones active with switch E3 E4 E5 take this code
	tmp = interupteurs;
	tmp = tmp & 0x04;
	tmp = tmp >> 2;
	set_zones_active1(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x08;
	tmp = tmp >> 3;
	set_zones_active2(tmp);
    tmp = interupteurs;
	tmp = tmp & 0x10;
	tmp = tmp >> 4;
	set_zones_active3(tmp);
*/
    return 0;
}

/* Output.c */

int port_g()
{
    unsigned char *portg,*ddrg;
    portg=(unsigned char *)0x02;
    /*Cast values into pointers*/
    ddrg=(unsigned char *)0x03;
    *ddrg=0xff;
    /*Set DDRA to all outputs*/

    /* treatment */
    if(everything_is_safe()) /* everything is safe */
    {
        *portg = 0x00; /* no light */
    }
    else
    {
        *portg = 0x01; /* light */
    }

    return 0;
}

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
    return_time_microprocessor(string_time); /* put the current time on the string */
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

/* Alarm.c */

struct Alarms
{
    int alarm1;
    int alarm2;
    int alarm3;
	int alarm4;
	int alarm5;
	int alarm6;
	int alarm7;
	int alarm8;
	int alarm9;
};

struct Zones
{
	int zone1;
	int zone2;
	int zone3;
};

struct Alarms alarms;
struct Zones zones;
struct Zones zones_active;

int init_alarms()
{
    alarms.alarm1 = 1;
    alarms.alarm2 = 1;
    alarms.alarm3 = 1;
    alarms.alarm4 = 1;
    alarms.alarm5 = 1;
    alarms.alarm6 = 1;
    alarms.alarm7 = 1;
    alarms.alarm8 = 1;
    alarms.alarm9 = 1;
    return 0;
}

int init_zone()
{
    zones.zone1 = 1;
    zones.zone2 = 1;
    zones.zone3 = 1;
    return 0;
}

int init_zone_active()
{
    zones_active.zone1 = 0;
    zones_active.zone2 = 0;
    zones_active.zone3 = 0;
    return 0;
}

int update_zones()
{
	if (alarms.alarm1 == 1 && alarms.alarm2 == 1 && alarms.alarm3 == 1)
	{
		zones.zone1 = 1;
	}
	else
	{
		zones.zone1 = 0;
	}
	if (alarms.alarm4 == 1 && alarms.alarm5 == 1 && alarms.alarm6 == 1)
	{
		zones.zone2 = 1;
	}
	else
	{
		zones.zone2 = 0;
	}
	if (alarms.alarm7 == 1 && alarms.alarm8 == 1 && alarms.alarm9 == 1)
	{
		zones.zone3 = 1;
	}
	else
	{
		zones.zone3 = 0;
	}
	return 0;
}

int get_alarm1()
{
    return alarms.alarm1;
}

int set_alarm1(int new_alarm1)
{
    alarms.alarm1=new_alarm1;
    return 0;
}

int get_alarm2()
{
    return alarms.alarm2;
}

int set_alarm2(int new_alarm2)
{
    alarms.alarm2=new_alarm2;
    return 0;
}

int get_alarm3()
{
    return alarms.alarm3;
}

int set_alarm3(int new_alarm3)
{
    alarms.alarm3=new_alarm3;
    return 0;
}

int get_alarm4()
{
    return alarms.alarm4;
}

int set_alarm4(int new_alarm4)
{
    alarms.alarm4=new_alarm4;
    return 0;
}

int get_alarm5()
{
    return alarms.alarm5;
}

int set_alarm5(int new_alarm5)
{
    alarms.alarm5=new_alarm5;
    return 0;
}

int get_alarm6()
{
    return alarms.alarm6;
}

int set_alarm6(int new_alarm6)
{
    alarms.alarm6=new_alarm6;
    return 0;
}

int get_alarm7()
{
    return alarms.alarm7;
}

int set_alarm7(int new_alarm7)
{
    alarms.alarm7=new_alarm7;
    return 0;
}

int get_alarm8()
{
    return alarms.alarm8;
}

int set_alarm8(int new_alarm8)
{
    alarms.alarm8=new_alarm8;
    return 0;
}

int get_alarm9()
{
    return alarms.alarm9;
}

int set_alarm9(int new_alarm9)
{
    alarms.alarm9=new_alarm9;
    return 0;
}

int get_zone1()
{
    return zones.zone1;
}

int get_zone2()
{
    return zones.zone2;
}

int get_zone3()
{
    return zones.zone3;
}

int get_zones_active1()
{
    return zones_active.zone1;
}

int set_zones_active1(int new_zones_active1)
{
    zones_active.zone1=new_zones_active1;
    return 0;
}

int get_zones_active2()
{
    return zones_active.zone2;
}

int set_zones_active2(int new_zones_active2)
{
    zones_active.zone2=new_zones_active2;
    return 0;
}

int get_zones_active3()
{
    return zones_active.zone3;
}

int set_zones_active3(int new_zones_active3)
{
    zones_active.zone3=new_zones_active3;
    return 0;
}

int everything_is_safe()
{
    int safe = 1;
    if(zones_active.zone1)
    {
        if(!(alarms.alarm1 && alarms.alarm2 && alarms.alarm3))
        {
            safe = 0;
        }
    }
    if(zones_active.zone2)
    {
        if(!(alarms.alarm4 && alarms.alarm5 && alarms.alarm6))
        {
            safe = 0;
        }
    }
    if(zones_active.zone3)
    {
        if(!(alarms.alarm7 && alarms.alarm8 && alarms.alarm9))
        {
            safe = 0;
        }
    }
    return safe;
}

/* MyTime.c */

int return_time_microprocessor(char *string_time)
{
    sprintf(string_time,"%dh %dm %ds ",hours,mins,secs);
    return 0;
}
