#include "main.h"

int main(void)
{
    char cmd;
    Player *player = player_init(50,50);

    system("/bin/stty raw");
    __clear;

    while((int)(cmd = getchar()) != KEY_EXIT)
    {
        __clear;

        switch(cmd)
        {
            case KEY_RIGHT:
                player_move(player,PLAYER_RIGHT,1);
                break;
            case KEY_LEFT:
                player_move(player,PLAYER_LEFT,1);
                break;
            case KEY_UP:
                player_move(player,PLAYER_UP,1);
                break;
            case KEY_DOWN:
                player_move(player,PLAYER_DOWN,1);
                break;
        }

        printf("(%i,%i)",player->x,player->y);
    }

    system("/bin/stty cooked");
    __clear;

    return 0;
}