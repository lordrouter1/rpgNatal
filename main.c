/* NECESSÁRIO INSTALAR A libncurses5-dev */

#include <ncurses.h>

int main(void)
{
    char cmd;

    initscr();
    raw();
    keypad(stdscr,TRUE);
    noecho();

    while((cmd = getch()) != 27)
    {

    }

    endwin();

    return 0;
}