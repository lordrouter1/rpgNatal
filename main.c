#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char cmd;

    system("/bin/stty raw");

    while((int)(cmd = getchar()) != 27);

    system("/bin/stty cooked");

    return 0;
}