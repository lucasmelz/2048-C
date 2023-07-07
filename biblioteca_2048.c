#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "biblioteca_2048.h"

int direita (int grelha[][10], int sz)
{
    int numerodecombinacoes = 0;
    int i, j, h; //contadores dos for's, h� um contador adicional pois ele serve para percorrer as linhas � procura de 0's
    int count = 0; //serve para contar o n�mero de 0's(n�mero de posi��es livres) � direita



    for (i=0; i<sz; i++) /* joga os numeros para a direita se houver posi��es livres (com 0's) */
    {
        for(j=sz-2; j>=0; j--) //inicializa-se em sz-2(pen�ltima coluna) pois as compara��es s�o feitas com a coluna � direita
        {
            if(grelha[i][j]!=0) //se a posi��o estiver ocupada
            {
                for(h=j+1; h<sz; h++) //esse for serve para contar as posi��es livres � direita
                {
                    if(grelha[i][h]==0)
                    {
                        count++; //esse contador ser� incrementado a cada zero que houver � direita do n�mero na posi��o [i][j]
                    }
                }
                if(count>0) //se houver posi��es livres � direita
                {
                    grelha[i][j+count]=grelha[i][j]; //o n�mero na posi��o [i][j] ser� "deslocado" para a direita
                    grelha[i][j]=0; //a posi��o do n�mero deslocado � liberada
                }
            }
            count = 0; //o contador de 0's � zerado para ser reutilizado
        }
    }



    for (i=0; i<sz; i++)   /* soma os numeros iguais */
    {
        for(j=sz-1; j>0; j--) //percorre-se a fun��o da direita para a esquerda
        {
            if(grelha[i][j]==grelha[i][j-1] && grelha[i][j]!=0) //se a posi��o em quest�o for ocupada por um n�mero diferente de 0 e houver um n�mero igual � esquerda
            {
                grelha[i][j]=grelha[i][j]*2; //o n�mero � direita passa ao dobro
                grelha[i][j-1]=0; //o n�mero � esquerda recebe um 0 (a posi��o � liberada)
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
    int i, j, h; //contadores dos for's, h� um contador adicional pois ele serve para percorrer as linhas � procura de 0's
    int count = 0; //serve para contar o n�mero de 0's(n�mero de posi��es livres) � esquerda



    for (i=0; i<sz; i++)  /* joga os numeros para a esquerda se houver posi��es livres (com 0's) */
    {
        for(j=1; j<sz; j++) //inicializa-se em 1 (segunda coluna) pois as compara��es s�o feitas com a coluna � esquerda
        {
            if(grelha[i][j]!=0) //se a posi��o estiver ocupada
            {
                for(h=j-1; h>=0; h--) //esse for serve para contar as posi��es livres � esquerda
                {
                    if(grelha[i][h]==0)
                    {
                        count++; //esse contador ser� incrementado a cada zero que houver � esquerda do n�mero na posi��o [i][j]
                    }
                }
                if(count>0) //se houver posi��es livres � esquerda
                {
                    grelha[i][j-count]=grelha[i][j]; //o n�mero na posi��o [i][j] ser� "deslocado" para a direita
                    grelha[i][j]=0; //a posi��o do n�mero deslocado ser� "liberada"
                }
            }
            count = 0; //o contador de zeros recebe o valor 0 para poder ser reutilizado
        }
    }



    for (i=0; i<sz; i++)     /* nos pr�ximos dois for's a matriz ser� percorrida para somar os numeros iguais */
    {
        for(j=0; j<sz-1; j++) //a matriz � percorrida da esquerda para a direita
        {
            if(grelha[i][j]==grelha[i][j+1] && grelha[i][j]!=0) //se a posi��o em quest�o for ocupada por um n�mero diferente de 0 e houver um n�mero igual � direita
            {
                grelha[i][j]=grelha[i][j]*2; //o n�mero � esquerda passa ao dobro
                grelha[i][j+1]=0; //o n�mero � direita recebe o valor 0, isto �, a posi��o � liberada
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
    int count = 0; //serve para contar o n�mero de 0's(n�mero de posi��es livres) abaixo
    int i, j, h; //contadores dos for's, h� um contador adicional pois ele serve para percorrer as colunas � procura de 0's

    for(i=sz-2; i>=0; i--) /* estes dois for's jogam os numeros para baixo se houver posi��es livres (com 0's) */
    {
        for (j=0; j<sz; j++)
        {
            if(grelha[i][j]!=0) //se a posi��o estiver ocupada
            {
                for(h=i+1; h<sz; h++) //esse for serve para verificar se h� posi��es livres abaixo da posi��o [i][j]
                {
                    if(grelha[h][j]==0)
                    {
                        count++; //o contador � incrementado se houver 0's abaixo da posi��o [i][j]
                    }
                }

                if (count>0) // se houver posi��es livres abaixo da posi��o [i][j]
                {
                    grelha[i+count][j]=grelha[i][j]; //"desloca-se" o valor que est� em [i][j] para baixo
                    grelha[i][j]=0; //a posi��o do n�mero "deslocado" recebe o valor 0
                }
            }
            count = 0; //o contador de 0's � reinicializado para a pr�xima itera��o


        }
    }

    for (i=sz-1; i>0; i--) /* nos pr�ximos dois for's a matriz ser� percorrida para somar os numeros iguais */
    {
        for(j=0; j<sz; j++)
        {
            if(grelha[i][j]==grelha[i-1][j] && grelha[i][j]!=0) //se o n�mero acima da posi��o [i][j] for igual e se o valor de [i][j] for diferente de 0
            {
                grelha[i][j]=grelha[i][j]*2; //o n�mero que est� em [i][j] passa ao dobro (� "combinado" com o n�mero acima)
                grelha[i-1][j]=0; //a posi��o acima de [i][j] � liberada
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
    int count = 0; //serve para contar o n�mero de 0's(n�mero de posi��es livres) acima, o que ser� necess�rio para deslocar os n�meros para cima
    int i, j, h; //contadores dos for's, h� um contador adicional pois ele serve para percorrer as colunas � procura de 0's

    for(i=1; i<sz; i++) /* estes dois for's jogam os numeros para cima se houver posi��es livres (com 0's) */
    {
        for (j=0; j<sz; j++)
        {
            if(grelha[i][j]!=0) //se a posi��o [i][j] estiver ocupada
            {
                for(h=i-1; h>=0; h--) //esse for serve para verificar se h� posi��es livres acima da posi��o [i][j]
                {
                    if(grelha[h][j]==0)
                    {
                        count++; //o contador � incrementado se houver 0's acima da posi��o [i][j]
                    }
                }

                if (count>0) // se houver posi��es livres acima da posi��o [i][j]
                {
                    grelha[i-count][j]=grelha[i][j]; //"desloca-se" o valor que est� em [i][j] para cima
                    grelha[i][j]=0; //a posi��o do n�mero "deslocado" recebe o valor 0
                }
            }
            count = 0; //o contador de 0's � reinicializado para a pr�xima itera��o


        }
    }

    for (i=0; i<sz-1; i++) /* nestes dois for's a matriz ser� percorrida para somar os numeros iguais */
    {
        for(j=0; j<sz; j++)
        {
            if(grelha[i][j]==grelha[i+1][j] && grelha[i][j]!=0) //se o n�mero abaixo da posi��o [i][j] for igual e se o valor de [i][j] for diferente de 0
            {
                grelha[i][j]=grelha[i][j]*2;  //o n�mero que est� em [i][j] passa ao dobro (� "combinado" com o n�mero que est� abaixo)
                grelha[i+1][j]=0; //a posi��o que est� abaixo de [i][j] � liberada
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

int jogada(int grelha[][10], int sz, char sentido[]) //fun��o respons�vel por chamar a fun��o que executa a jogada conforme o input
{
    int ncomb=0; //ncomb � um contador que recebe o n�mero de combina��es de uma �nica jogada
    if(strcasecmp(sentido, "B")==0) //se o input for igual ao caracter "B", a fun��o strcasecmp deve retornar o valor 0
    {
        ncomb = baixo(grelha, sz); //executa-se a jogada, ncomb recebe o n�mero de combina��es realizadas numa jogada, que � o retorno das fun��es de movimento
    }
    else if(strcasecmp(sentido, "C")==0) //o mesmo algoritmo explicado acima se repete durante toda a fun��o considerando os diferentes movimentos poss�veis...
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
    return ncomb; //� retornado o n�mero de combina��es
}
void conta_pecas (int grelha[][10], int sz)
{
    int pecas[11]; //esse array guarda o n�mero de pe�as, existem 11 posi��es no array pois s�o 11 pot�ncias de 2 at� o n�mero 2048
    for(int i=0; i<11; i++)
    {
        pecas[i]=0; //todas as posi��es do array s�o inicializadas em 0
    }

    for (int i = 0; i<sz; i++) //estes dois for's percorrer�o a matriz para que o n�mero de pe�as seja contabilizado
    {
        for (int j = 0; j<sz; j++)
        {
            if (grelha[i][j]<=64) //entra-se neste if caso o n�mero na posi��o [i][j] seja 2, 4, 8, 16, 32 ou 64
            {
                if(grelha[i][j]<=8) //se o n�mero da posi��o [i][j] for 2, 4 ou 8
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
            else // as instru��es do else ser�o executadas se o n�mero na posi��o [i][j] for 128, 256, 512, 1024 ou 2048
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
    for(int i=0; i<11; i++) //esse for � respons�vel por imprimir o n�mero das pe�as presentes no tabuleiro
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
            if(!grelha[r][t]) //se o n�mero na posi��o [r][t] for 0, que indica uma posi��o livre, imprime-se um travess�o
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
