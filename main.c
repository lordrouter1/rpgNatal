<<<<<<< HEAD
#include "main.h"
=======
/* NECESSÁRIO INSTALAR A libncurses5-dev */

#include <ncurses.h>
>>>>>>> master

int main(void)
{
    char cmd;

<<<<<<< HEAD
    system("/bin/stty raw");
    system("clear");

    while((int)(cmd = getchar()) != 27)
    {
        system("clear");
        printf("%i",cmd);
    }

    system("/bin/stty cooked");
    system("clear");
=======
    initscr();
    raw();
    keypad(stdscr,TRUE);
    noecho();

    while((cmd = getch()) != 27)
    {

    }

    endwin();
>>>>>>> master

    return 0;
}