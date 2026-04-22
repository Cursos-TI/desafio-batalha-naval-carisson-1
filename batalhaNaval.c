#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
int  tabuleiro[LINHAS][COLUNAS];
 
for (int i = 0; i < 10; i++)
{   for (int j = 0; j < 10; j++)
{
     tabuleiro[i][j] = 0;
}
}

//Posicionar navio horizontal
for (int j = 6; j <= 8; j++)
{
    tabuleiro[4][j] = 3;
}

//Posicionar navio vertical

for (int i = 4; i <= 6 ; i++) 
{
   tabuleiro[i][1] = 3;
}

//Posicionar navio diagonal esquerda

int linha = 7;
int coluna = 6;
for (int i = 0; i < 3; i++)
{
    tabuleiro[linha - i][coluna - i] = 3;
}

//Posicionar navio diagonal direita

int linhadir = 2;
int colunadir = 6;
for (int i = 0; i < 3; i++)
{
    tabuleiro[linhadir - i][colunadir + i] = 3;
}
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    //cabeçalho da coluna
printf("  ");
for (char c = 'A'; c <= 'J'; c++)
{
    printf("  ");
    printf("%c", c);
    
}
printf("\n");

//Linhas numeradas
for (int i = 0; i < 10; i++)
{
    printf("%2d", i + 1);
    for (int j = 0; j < 10; j++)
    {
        printf("  ");
        printf("%d", tabuleiro[i][j]);
        
    }
    printf("\n");
}

    return 0;
}
