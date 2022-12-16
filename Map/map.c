bool draw_map(Player *_p,int _level)
{
    open_map(_level);

    return false;
}

Mapa *open_map(int _level)
{
    char p;
    char conv[20];
    char *buf;
    int x = 0;
    int y = 0;
    int size;
    int cont = 0;

    FILE *mp;
    Mapa *sMp = malloc(sizeof(Mapa));

    sprintf(conv,"Map/Level/map_%d",_level);
    
    mp = fopen(conv,"r");
    
    if(!mp)
        printf("erro!");
    else
    {
        fseek(mp,0,SEEK_END);
        size = ftell(mp);
        fseek(mp,0,SEEK_SET);

        buf = malloc(sizeof(char)*size);

        while(true)
        {
            p = fgetc(mp);
            if(p == EOF) break;
            buf[cont++] = p;
            if(p == 'o')
            {
                sMp->pInitX = y;
                sMp->pInitY = x;
            }
            if(p == '\n')
            {
                y++;
                x = 0;
            }
            else x++;
        }
        sMp->xMax = y+1;
        sMp->yMax = x;
        fclose(mp);

        printf("%i,%i\n",sMp->pInitX,sMp->pInitY);

        cont = 0;
        sMp->map = malloc(sizeof(char *)*sMp->xMax);
        for(int i = 0; i < sMp->xMax; i++)
        {
            sMp->map[i] = malloc(sizeof(char)*sMp->yMax);
            for(int j = 0; j < sMp->yMax;j++)
            {
                sMp->map[i][j] = (buf[cont] == 'o'?' ':buf[cont]);
                cont++;
            }
            cont++;
        }

        for(int i = 0; i < sMp->xMax; i++)
        {
            for(int j = 0; j < sMp->yMax; j++)
            {
                printf("%c",sMp->map[i][j]);
            }
            printf("\n");
        }
    }

    return sMp;
}