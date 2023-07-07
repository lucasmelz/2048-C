#ifndef BIBLIOTECA_2048_H_INCLUDED
#define BIBLIOTECA_2048_H_INCLUDED

int direita (int grelha[][10], int sz);
int esquerda (int grelha[][10], int sz);
int baixo (int grelha[][10], int sz);
int cima (int grelha[][10], int sz);
int jogada(int grelha[][10], int sz, char sentido[]);
void mostrar (int grelha[][10], int sz);
void conta_pecas (int grelha[][10], int sz);

#endif // BIBLIOTECA_2048_H_INCLUDED
