#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "biblioteca_2048.h"

int direita (int grelha[][10], int sz)
{
    int numerodecombinacoes = 0;
    int i, j, h; //contadores dos for's, há um contador adicional pois ele serve para percorrer as linhas à procura de 0's
    int count = 0; //serve para contar o número de 0's(número de posições livres) à direita



    for (i=0; i<sz; i++) /* joga os numeros para a direita se houver posições livres (com 0's) */
    {
        for(j=sz-2; j>=0; j--) //inicializa-se em sz-2(penúltima coluna) pois as comparações são feitas com a coluna à direita
        {
            if(grelha[i][j]!=0) //se a posição estiver ocupada
            {
                for(h=j+1; h<sz; h++) //esse for serve para contar as posições livres à direita
                {
                    if(grelha[i][h]==0)
                    {
                        count++; //esse contador será incrementado a cada zero que houver à direita do número na posição [i][j]
                    }
                }
                if(count>0) //se houver posições livres à direita
                {
                    grelha[i][j+count]=grelha[i][j]; //o número na posição [i][j] será "deslocado" para a direita
                    grelha[i][j]=0; //a posição do número deslocado é liberada
                }
            }
            count = 0; //o contador de 0's é zerado para ser reutilizado
        }
    }



    for (i=0; i<sz; i++)   /* soma os numeros iguais */
    {
        for(j=sz-1; j>0; j--) //percorre-se a função da direita para a esquerda
        {
            if(grelha[i][j]==grelha[i][j-1] && grelha[i][j]!=0) //se a posição em questão for ocupada por um número diferente de 0 e houver um número igual à esquerda
            {
                grelha[i][j]=grelha[i][j]*2; //o número à direita passa ao dobro
                grelha[i][j-1]=0; //o número à esquerda recebe um 0 (a posição é liberada)
                numerodecombinacoes++;
                int aux = j-1;

                while(aux>0 && grelha[i][aux]==0)
                {
                    grelha[i][aux] = grelha[i][aux-1];
                    grelha[i][aux-1] = 0;
                    aux--;
                }
            }


        }
    }


    return numerodecombinacoes;
}

int esquerda (int grelha[][10], int sz)
{
    int numerodecombinacoes = 0;
    int i, j, h; //contadores dos for's, há um contador adicional pois ele serve para percorrer as linhas à procura de 0's
    int count = 0; //serve para contar o número de 0's(número de posições livres) à esquerda



    for (i=0; i<sz; i++)  /* joga os numeros para a esquerda se houver posições livres (com 0's) */
    {
        for(j=1; j<sz; j++) //inicializa-se em 1 (segunda coluna) pois as comparações são feitas com a coluna à esquerda
        {
            if(grelha[i][j]!=0) //se a posição estiver ocupada
            {
                for(h=j-1; h>=0; h--) //esse for serve para contar as posições livres à esquerda
                {
                    if(grelha[i][h]==0)
                    {
                        count++; //esse contador será incrementado a cada zero que houver à esquerda do número na posição [i][j]
                    }
                }
                if(count>0) //se houver posições livres à esquerda
                {
                    grelha[i][j-count]=grelha[i][j]; //o número na posição [i][j] será "deslocado" para a direita
                    grelha[i][j]=0; //a posição do número deslocado será "liberada"
                }
            }
            count = 0; //o contador de zeros recebe o valor 0 para poder ser reutilizado
        }
    }



    for (i=0; i<sz; i++)     /* nos próximos dois for's a matriz será percorrida para somar os numeros iguais */
    {
        for(j=0; j<sz-1; j++) //a matriz é percorrida da esquerda para a direita
        {
            if(grelha[i][j]==grelha[i][j+1] && grelha[i][j]!=0) //se a posição em questão for ocupada por um número diferente de 0 e houver um número igual à direita
            {
                grelha[i][j]=grelha[i][j]*2; //o número à esquerda passa ao dobro
                grelha[i][j+1]=0; //o número à direita recebe o valor 0, isto é, a posição é liberada
                numerodecombinacoes++;

                int aux = j+1;

                while(aux<sz-1 && grelha[i][aux]==0)
                {
                    grelha[i][aux] = grelha[i][aux+1];
                    grelha[i][aux+1] = 0;
                    aux++;
                }
            }

        }
    }

    return numerodecombinacoes;
}






int baixo (int grelha[][10], int sz)
{
    int numerodecombinacoes = 0;
    int count = 0; //serve para contar o número de 0's(número de posições livres) abaixo
    int i, j, h; //contadores dos for's, há um contador adicional pois ele serve para percorrer as colunas à procura de 0's

    for(i=sz-2; i>=0; i--) /* estes dois for's jogam os numeros para baixo se houver posições livres (com 0's) */
    {
        for (j=0; j<sz; j++)
        {
            if(grelha[i][j]!=0) //se a posição estiver ocupada
            {
                for(h=i+1; h<sz; h++) //esse for serve para verificar se há posições livres abaixo da posição [i][j]
                {
                    if(grelha[h][j]==0)
                    {
                        count++; //o contador é incrementado se houver 0's abaixo da posição [i][j]
                    }
                }

                if (count>0) // se houver posições livres abaixo da posição [i][j]
                {
                    grelha[i+count][j]=grelha[i][j]; //"desloca-se" o valor que está em [i][j] para baixo
                    grelha[i][j]=0; //a posição do número "deslocado" recebe o valor 0
                }
            }
            count = 0; //o contador de 0's é reinicializado para a próxima iteração


        }
    }

    for (i=sz-1; i>0; i--) /* nos próximos dois for's a matriz será percorrida para somar os numeros iguais */
    {
        for(j=0; j<sz; j++)
        {
            if(grelha[i][j]==grelha[i-1][j] && grelha[i][j]!=0) //se o número acima da posição [i][j] for igual e se o valor de [i][j] for diferente de 0
            {
                grelha[i][j]=grelha[i][j]*2; //o número que está em [i][j] passa ao dobro (é "combinado" com o número acima)
                grelha[i-1][j]=0; //a posição acima de [i][j] é liberada
                numerodecombinacoes++;
                int aux = i-1;

                while(aux>0 && grelha[aux][j]==0)
                {
                    grelha[aux][j] = grelha[aux-1][j];
                    grelha[aux-1][j] = 0;
                    aux--;
                }


            }


        }
    }

    return numerodecombinacoes;
}

int cima (int grelha[][10], int sz)
{
    int numerodecombinacoes = 0;
    int count = 0; //serve para contar o número de 0's(número de posições livres) acima, o que será necessário para deslocar os números para cima
    int i, j, h; //contadores dos for's, há um contador adicional pois ele serve para percorrer as colunas à procura de 0's

    for(i=1; i<sz; i++) /* estes dois for's jogam os numeros para cima se houver posições livres (com 0's) */
    {
        for (j=0; j<sz; j++)
        {
            if(grelha[i][j]!=0) //se a posição [i][j] estiver ocupada
            {
                for(h=i-1; h>=0; h--) //esse for serve para verificar se há posições livres acima da posição [i][j]
                {
                    if(grelha[h][j]==0)
                    {
                        count++; //o contador é incrementado se houver 0's acima da posição [i][j]
                    }
                }

                if (count>0) // se houver posições livres acima da posição [i][j]
                {
                    grelha[i-count][j]=grelha[i][j]; //"desloca-se" o valor que está em [i][j] para cima
                    grelha[i][j]=0; //a posição do número "deslocado" recebe o valor 0
                }
            }
            count = 0; //o contador de 0's é reinicializado para a próxima iteração


        }
    }

    for (i=0; i<sz-1; i++) /* nestes dois for's a matriz será percorrida para somar os numeros iguais */
    {
        for(j=0; j<sz; j++)
        {
            if(grelha[i][j]==grelha[i+1][j] && grelha[i][j]!=0) //se o número abaixo da posição [i][j] for igual e se o valor de [i][j] for diferente de 0
            {
                grelha[i][j]=grelha[i][j]*2;  //o número que está em [i][j] passa ao dobro (é "combinado" com o número que está abaixo)
                grelha[i+1][j]=0; //a posição que está abaixo de [i][j] é liberada
                numerodecombinacoes++;
                int aux = i+1;

                while(aux<sz-1 && grelha[aux][j]==0)
                {
                    grelha[aux][j] = grelha[aux+1][j];
                    grelha[aux+1][j] = 0;
                    aux++;
                }


            }


        }
    }

    return numerodecombinacoes;
}

int jogada(int grelha[][10], int sz, char sentido[]) //função responsável por chamar a função que executa a jogada conforme o input
{
    int ncomb=0; //ncomb é um contador que recebe o número de combinações de uma única jogada
    if(strcasecmp(sentido, "B")==0) //se o input for igual ao caracter "B", a função strcasecmp deve retornar o valor 0
    {
        ncomb = baixo(grelha, sz); //executa-se a jogada, ncomb recebe o número de combinações realizadas numa jogada, que é o retorno das funções de movimento
    }
    else if(strcasecmp(sentido, "C")==0) //o mesmo algoritmo explicado acima se repete durante toda a função considerando os diferentes movimentos possíveis...
    {
        ncomb = cima(grelha, sz);
    }
    else if(strcasecmp(sentido, "D")==0)
    {
        ncomb = direita(grelha, sz);
    }
    else if(strcasecmp(sentido, "E")==0)
    {
        ncomb = esquerda(grelha, sz);
    }
    return ncomb; //é retornado o número de combinações
}
void conta_pecas (int grelha[][10], int sz)
{
    int pecas[11]; //esse array guarda o número de peças, existem 11 posições no array pois são 11 potências de 2 até o número 2048
    for(int i=0; i<11; i++)
    {
        pecas[i]=0; //todas as posições do array são inicializadas em 0
    }

    for (int i = 0; i<sz; i++) //estes dois for's percorrerão a matriz para que o número de peças seja contabilizado
    {
        for (int j = 0; j<sz; j++)
        {
            if (grelha[i][j]<=64) //entra-se neste if caso o número na posição [i][j] seja 2, 4, 8, 16, 32 ou 64
            {
                if(grelha[i][j]<=8) //se o número da posição [i][j] for 2, 4 ou 8
                {
                    if(grelha[i][j]==2)
                    {
                        pecas[0]=pecas[0]+1;
                    }
                    else
                    {
                        if(grelha[i][j]==4)
                        {
                            pecas[1] = pecas[1]+1;
                        }
                        if(grelha[i][j]==8)
                        {
                            pecas[2]=pecas[2]+1;
                        }
                    }
                }

                else // se for menor ou igual a 64 e maior que 8
                {
                    if(grelha[i][j]==16)
                    {
                        pecas[3]=pecas[3]+1;
                    }
                    else
                    {
                        if(grelha[i][j]==32)
                        {
                            pecas[4]=pecas[4]+1;
                        }
                        else
                        {
                            pecas[5]=pecas[5]+1;
                        }
                    }
                }

            }
            else // as instruções do else serão executadas se o número na posição [i][j] for 128, 256, 512, 1024 ou 2048
            {
                if(grelha[i][j]<=512)
                {
                    if(grelha[i][j]==128)
                    {
                        pecas[6]=pecas[6]+1;
                    }
                    else
                    {
                        if(grelha[i][j]==256)
                        {
                            pecas[7]=pecas[7]+1;
                        }
                        if(grelha[i][j]==512)
                        {
                            pecas[8]=pecas[8]+1;
                        }
                    }
                }
                else // se for 1024 ou 2048
                {
                    if(grelha[i][j]==1024)
                    {
                        pecas[9]=pecas[9]+1;
                    }
                    if(grelha[i][j]==2048)
                    {
                        pecas[10]=pecas[10]+1;
                    }
                }

            }

        }
    }
    for(int i=0; i<11; i++) //esse for é responsável por imprimir o número das peças presentes no tabuleiro
    {
        if(pecas[i]!=0)
        {
            printf("Quantidade de pecas com o valor %d: %d.\n", (int)pow(2,(i+1)), pecas[i]);
        }
    }

}
void mostrar (int grelha[][10], int sz) //imprime a matriz
{
    for (int r=0; r<sz; r++)
    {
        for (int t=0; t<sz; t++)
        {
            if(!grelha[r][t]) //se o número na posição [r][t] for 0, que indica uma posição livre, imprime-se um travessão
            {
                printf("%3s ", "-");
            }
            else
            {
                printf("%3d ", grelha[r][t]);
            }
        }
        printf("\n");
    }

    printf("\n");
}
