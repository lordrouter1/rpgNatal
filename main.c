#include "main.h"

int main(void)
{
    char cmd;

    system("/bin/stty raw");
    system("clear");

    while((int)(cmd = getchar()) != 27)
    {
        system("clear");
        printf("%i",cmd);
    }

    system("/bin/stty cooked");
    system("clear");

    return 0;
}