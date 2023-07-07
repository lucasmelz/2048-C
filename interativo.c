#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "biblioteca_2048.h"

int geranumero() //gera 2 ou 4 de forma aleat�ria (50% de chance de retornar 2, 50% de chance de retornar 4)
{
    int a = rand()%4; // gera um n�mero de 0 a 3
    if(a<2) // se a for 0 ou 1, retorna 2, se for 2 ou 3, retorna 4, assim h� 50% de chance de retornar 2's ou 4's
    {
        return 2;
    }
    else
        return 4;
}

void inicializagrelha(int grelha[][10], int sz) //inicializa a matriz com dois n�meros (2 ou 4) em posi��es aleat�rias
{
    int linha0 = rand()%sz; //linha0 e coluna0 s�o a linha e a coluna do primeiro n�mero a ser inserido na grelha
    int coluna0 = rand()%sz;
    for (int r=0; r<sz; r++) // preenche a matriz com 0's para evitar que exista lixo de mem�ria nas posi��es da matriz
    {
        for (int t=0; t<sz; t++)
        {
            grelha[r][t]=0;
        }

    }

    grelha[linha0][coluna0] = geranumero(); //aqui uma posi��o aleat�ria da matriz recebe o valor 2 ou 4

    int linha1 = rand()%sz; //linha1 e coluna1 s�o a linha e a coluna do segundo n�mero a ser inserido na matriz em uma posi��o aleat�ria
    int coluna1 = rand()%sz;
    while (linha0==linha1 && coluna0==coluna1) //este while garante que o segundo n�mero n�o seja inserido na mesma posi��o que o primeiro
    {
        linha1 = rand()%sz;
        coluna1 = rand()%sz;
    }
    grelha[linha1][coluna1] = geranumero();


}

void novonumero(int grelha[][10], int sz) //essa fun��o � respons�vel por inserir um novo n�mero na matriz a cada jogada
{
    int linha = rand()%sz;
    int coluna = rand()%sz; //aqui � escolhida uma posi��o aleat�ria da matriz

    while (grelha[linha][coluna]!=0) //este while garante que a posi��o escolhida j� n�o esteja ocupada
    {
        linha=rand()%sz;
        coluna=rand()%sz;
    }
    grelha[linha][coluna]= geranumero();
}

void fim_de_jogo(int grelha[][10], int sz, int numero_total_de_comb) //essa fun��o � respons�vel pela vit�ria ou game over do modo interativo
{
    int i, j; //i e j s�o contadores dos for's utilizados para percorrer a matriz
    int controle1 = 0; //controle1 serve para verificar quantas posi��es da matriz est�o ocupadas por n�meros
    int controle2 = 0; //controle2 serve para verificar quantos n�meros n�o podem ser combinados com n�meros a sua direita, esquerda, acima ou abaixo

    for(i=0; i<sz; i++)
    {
        for (j=0; j<sz; j++)
        {
            if (grelha[i][j]==2048) //condi��o de vit�ria
            {
                printf("\nParabens, voce ganhou!\nO numero total de combinacoes durante o jogo foi:%d.", numero_total_de_comb);
                conta_pecas(grelha, sz);
                printf("Digite qualquer caracter para o programa encerrar.");
                fflush(stdin); //para evitar que haja caracteres sobrando no stdin, o que faria o programa encerrar de forma abrupta
                getchar(); //pausa no programa para que o usu�rio possa ler as mensagens do fim do jogo
                exit(1);
            }

            if(grelha[i][j]!=0)
            {
                controle1++; //incrementa-se controle1 quando � verificado que a posi��o da matriz est� ocupada
            }
            if(grelha[i][j]!=grelha[i+1][j] && grelha[i][j]!=grelha[i-1][j] && grelha[i][j]!=grelha[i][j-1] && grelha[i][j]!=grelha[i][j+1])
            {
                controle2++;//incrementa-se controle2 quando � verificado que o n�mero em quest�o n�o pode ser combinado com os n�meros acima, abaixo, � direita ou � esquerda
            }
        }


    }

    if (controle1==(sz*sz)&&controle2==(sz*sz)) //se todas as posi��es da matriz estiverem ocupadas e se todos os n�meros da matriz n�o puderem ser combinados
    {
        printf("Game over.\n");
        printf("O numero total de combinacoes durante o jogo foi: %d.\n", numero_total_de_comb);
        conta_pecas(grelha, sz);
        printf("Digite um caracter qualquer para o programa encerrar.");
        fflush(stdin);
        getchar();
        exit(1);
    }




}

int main()
{
    int sz;
    printf("Qual a dimensao da grelha? ");
    scanf("%d", &sz);
    srand(time(NULL));
    int grelha[10][10];
    inicializagrelha(grelha, sz); //chama-se a fun��o que preenche duas posi��es aleat�rias da matriz com os n�meros 2 ou 4
    char input[2];
    int numero_de_comb = 0; //essa vari�vel guarda o n�mero de combina��es de cada jogada
    int numero_total_de_comb = 0; //essa vari�vel guarda o n�mero de combina��es durante toda a execu��o do jogo

    mostrar(grelha, sz);

    while(strcasecmp(input, "F")!=0) //este while � respons�vel pela itera��o do jogo
    {
        printf("Sentido(F para sair): ");
        scanf("%s", input);
        if(strcasecmp(input, "F")==0) //este if encerra o jogo caso o input seja F
        {
			printf("O numero total de combinacoes durante o jogo foi: %d.\n", numero_total_de_comb);
			conta_pecas(grelha, sz);
            printf("A sair...");
            exit(1);
        }
        else //caso o input n�o seja F, executa-se uma jogada
        {
            numero_de_comb = jogada(grelha, sz, input); //chama-se a fun��o jogada, que al�m de executar a jogada, retorna o n�mero de combina��es realizadas
            numero_total_de_comb = numero_total_de_comb + numero_de_comb; //atualiza-ze o n�mero total de combina��es realizadas durante o jogo
            novonumero(grelha,sz); //insere um novo n�mero numa posi��o aleat�ria
            mostrar(grelha, sz);
            printf("Numero de combinacoes: %d\n\n", numero_de_comb);
            fim_de_jogo(grelha,sz,numero_total_de_comb); //verifica se o jogo pode continuar ou se deve ser encerrado (vit�ria ou game over)
        }
    }

    return 0;
}
