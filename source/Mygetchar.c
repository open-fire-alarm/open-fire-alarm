/* Mygetchar.c */

unsigned char mygetchar()
{
    unsigned char key;

    unsigned char *scsr, *scdr;

    scsr =(unsigned char *)0x2e;
    scdr = (unsigned char *)0x2f;

    if(*scsr & 0x20)
    {
        key = *scdr;
    }
    else
    {
        key = '\0';
    }

    return key;
}
