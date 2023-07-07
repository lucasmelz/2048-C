#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "biblioteca_2048.h"

void fim_de_jogo(int grelha[][10], int sz, int numero_total_de_comb, char *token)
{ //essa fun��o define o t�rmino de jogo em caso de vit�ria, caso n�o hajam mais combina��es poss�veis ou caso n�o exista mais inputs a serem lidos do ficheiro
    int i, j;

    for(i=0; i<sz; i++)
    {
        for (j=0; j<sz; j++)
        {
            if (grelha[i][j]==2048) //condi��o de vit�ria
            {
                printf("\nParabens, voce ganhou!\nO numero total de combinacoes durante o jogo foi:%d.\n", numero_total_de_comb);
                conta_pecas(grelha, sz);
                printf("Digite um caracter qualquer para o programa encerrar.");
                getchar(); //pausa para o programa n�o encerrar bruscamente
                exit(1);
            }
        }


    }

        if(token==NULL) //caso o input seja nulo, o jogo encerra, pois n�o h� mais jogadas a serem executadas
        {printf("Game over.\n");
        printf("O numero total de combinacoes durante o jogo foi: %d.\n", numero_total_de_comb);
        conta_pecas(grelha, sz);
        printf("Digite um caracter qualquer para o programa encerrar.");
        getchar(); //pausa para o programa n�o encerrar bruscamente
        exit(1);}

}

int main()
{

    int sz;
    int grelha[10][10];
    char input[2];
    int numero_de_comb = 0;
    int numero_total_de_comb = 0;
    char c;
    FILE *FICHEIRO;
    char texto_do_ficheiro[100];
    int i = 0;
    FICHEIRO = fopen("ficheiro.txt", "r");
    while((c = getc(FICHEIRO) ) != EOF)      /* Enquanto n�o chegar ao final do arquivo */
    { //esse while passa todo o conte�do do ficheiro para uma string
        texto_do_ficheiro[i]=c;
        i++;
    }
    texto_do_ficheiro[i]='\0'; //o final da string recebe um \0
    char aux[5]; //essa string auxiliar ir� guardar o conte�do dos tokens
    char *token; //token a ser utilizado para separar as informa��es do ficheiro
    char delim1[3] = " \n"; //delimitador usado na fun��o strtok, as informa��es do ficheiro s�o separadas por um espa�o em branco ou \n
    token = strtok(texto_do_ficheiro, delim1); //obt�m-se o primeiro token, que corresponder� � dimens�o da matriz
    strcpy(aux, token); //copia-se o conte�do do token para a string auxiliar
    sz = atoi(aux); //a vari�vel sz, que representa a dimens�o da matriz, recebe o n�mero que corresponde ao primeiro caracter do ficheiro

    for(int i = 0; i<sz; i++) //estes dois for's ir�o preencher a grelha com os valores n�meros presentes no ficheiro
    {
        for (int j = 0; j<sz; j++)
        {
            token = strtok(NULL, delim1);
            strcpy(aux, token);
            grelha[i][j]=atoi(aux);
        }
    }


    printf("Grelha inicial:\n\n");
    mostrar(grelha,sz); //� impressa a grelha inicial

    while(strcasecmp(input, "F")!=0) //este while � respons�vel pela itera��o, que deve continuar enquanto houverem jogadas a serem lidas do ficheiro
    {
        token = strtok(NULL, delim1); //obt�m-se o pr�ximo token, que deve ser uma letra correspondente ao sentido da jogada
        if(token!=NULL) //se o token n�o for nulo
        {strcpy(input, token);} //copia-se o token para a string que guarda o input relativo � jogada
        else //caso contr�rio o jogo acaba
            {
             fim_de_jogo(grelha, sz, numero_total_de_comb, token);
            }


        if(strcasecmp(input, "F")==0) //caso o input relativo � jogada seja o caracter F, o jogo encerra
        {
            printf("O numero total de combinacoes durante o jogo foi: %d.\n", numero_total_de_comb);
            conta_pecas(grelha, sz);
            printf("Digite um caracter qualquer para o programa encerrar.");
            getchar(); //pausa para o programa n�o encerrar bruscamente
            printf("A sair...");
            exit(1);
        }
        else
        {
            printf("Sentido: %s\n\n", input);
            numero_de_comb = jogada(grelha, sz, input);
            numero_total_de_comb = numero_total_de_comb + numero_de_comb;
            mostrar(grelha, sz);
            printf("Numero de combinacoes: %d\n\n", numero_de_comb);
            fim_de_jogo(grelha, sz, numero_total_de_comb, token); //chama-se a fun��o fim_de_jogo para verificar se o jogo pode continuar
        }
    }

    return 0;
}
