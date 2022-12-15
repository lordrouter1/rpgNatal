#ifndef __PLAYER__
#define __PLAYER__

#define PLAYER_UP 1
#define PLAYER_DOWN 2
#define PLAYER_RIGHT 3
#define PLAYER_LEFT 4

typedef struct
{
    int x;
    int y;
    int xMax;
    int yMax;
} Player;

#include "player.c"

#endif