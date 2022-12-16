bool draw_map(Player *_p,int _level)
{
    open_map(_level);

    return false;
}

Mapa *open_map(int _level)
{
    // Inicia váriávei
    char p;
    char conv[20];
    char *buf;
    int x = 0;
    int y = 0;
    int size;
    int cont = 0;

    FILE *mp;
    // Cria e aloca espaço na memória para a Struct Mapa
    Mapa *sMp = malloc(sizeof(Mapa));

    // Converte o inteiro referente ao level em uma string com o caminho do arquivo do mapa
    sprintf(conv,"Map/Level/map_%d",_level);
    
    // Abre o arquivo do mapa em modo de leitura
    mp = fopen(conv,"r");
    
    if(!mp)
        // Caso não ache o arquivo mostra erro
        printf("erro!");
    else
    {
        // Move o ponteiro para o final do arquivo
        fseek(mp,0,SEEK_END);
        // Conta o tamanho do arquivo
        size = ftell(mp);
        // Move o ponteiro para o inicio do arquivo
        fseek(mp,0,SEEK_SET);

        // Cria um buffer para armazenar todos os caracteres do arquivo em um array
        buf = malloc(sizeof(char)*size);

        // Inicia um loop infinito
        while(true)
        {
            // Armazena em p um caracter do arquivo
            p = fgetc(mp);
            // Se o caracter for igual a EOF finaliza o laço
            if(p == EOF) break;
            // Caso contrario armazena em buffer o caracter e incrementa o contador
            buf[cont++] = p;
            // Se p for igual a o, representa o player, adiciona na struct do mapa as cordenadas do personagem;
            if(p == 'o')
            {
                // A leitura é feita inversa;
                sMp->pInitX = y;
                sMp->pInitY = x;
            }
            // Se p for igual a quebra de linha, zera o contador de x e incrementa o contador de y
            if(p == '\n')
            {
                y++;
                x = 0;
            }
            // Incrementa o contador de x
            else x++;
        }
        // Define o tamanho do mapa
        sMp->xMax = y+1;
        sMp->yMax = x;
        // Fecha arquivo
        fclose(mp);

        // Zera o contador
        cont = 0;
        // Aloca o espaço de memória corespondente ao tamanho máximo de x no ponteiro do map
        sMp->map = malloc(sizeof(char *)*sMp->xMax);
        // Inicia um laço para percorrer o x
        for(int i = 0; i < sMp->xMax; i++)
        {
            // Aloca o espaço de memória correspondente ao tamanho máximo de y no ponteiro do map[x] 
            sMp->map[i] = malloc(sizeof(char)*sMp->yMax);
            // Inicia um laço para percorrer o y
            for(int j = 0; j < sMp->yMax;j++)
            {
                // Adiciona na matriz o caracter correspondente ao mapa, se o caracter for o player, subistitui por espaço em branco
                sMp->map[i][j] = (buf[cont] == 'o'?' ':buf[cont]);
                // Incremente o contador para ir ao próximo caracter
                cont++;
            }
            // Incrementa o contador para pular o caracter de quebra de linha
            cont++;
        }
    }

    // retorna a struct do mapa
    return sMp;
}