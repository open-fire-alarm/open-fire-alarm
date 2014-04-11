#include <stdio.h>
#include "Extraction.h"

/* Input.c */

int port_a()
{
    unsigned char *porta,*ddra;
    porta=(unsigned char *)0x00;
    /*Cast values into pointers*/
    ddra=(unsigned char *)0x01;
    *ddra=0x00;
    /*Set DDRA to all inputs*/

    extraction_port_a(*porta);

    return 0;
}

int port_e()
{
    unsigned char *porte;
    porte=(unsigned char *)0x0a;
    extraction_port_e(*porte);

    return 0;
}
