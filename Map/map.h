#ifndef __MAP__
#define __MAP__

#include <stdio.h>
#include <stdlib.h>

#include "../Player/player.h"

typedef struct
{
    int xMax;
    int yMax;
    int pInitX;
    int pInitY;
    int pEnd;
    char **map;
}Mapa;

bool draw_map(Player *_p,int _level);
Mapa *open_map(int _level);

#include "map.c"

#endif