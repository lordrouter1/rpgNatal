Player *player_init(int _xMax, int _yMax)
{
    Player *p = malloc(sizeof(Player));

    p->xMax = _xMax;
    p->yMax = _yMax;
    p->x = 0;
    p->y = 0;

    return p;
}

void player_move(Player *p,int _dest,int _distance)
{
    switch(_dest)
    {
        case PLAYER_UP:
            p->y += (p->y+_distance > p->yMax)?0:_distance;
            break;
        case PLAYER_DOWN:
            p->y -= (p->y-_distance < (p->yMax*-1))?0:_distance;
            break;
        case PLAYER_RIGHT:
            p->x += (p->x+_distance > p->xMax)?0:_distance;
            break;
        case PLAYER_LEFT:
            p->x -= (p->x-_distance < (p->yMax*-1))?0:_distance;
            break;
    }
}