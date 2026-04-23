#include <stdio.h>
#include <stdlib.h>  // Necessário para usar abs()

#define TAM 10        // tamanho fixo do tabuleiro
#define NAVIO 3       // valor que representa navio
#define AGUA 0        // valor que representa água
#define HABILIDADE 5  // valor que representa área de efeito
#define TAM_HAB 5     // tamanho fixo das matrizes de habilidade

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Exibe o tabuleiro com cabeçalho de colunas e numeração de linhas
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n   "); // espaço inicial para alinhar com numeração das linhas
    for (char c = 'a'; c < 'a' + TAM; c++) {
        printf("%c ", c); // imprime colunas de a até j
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1); // imprime número da linha (1 a 10)
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA) printf("0 ");
            else if (tabuleiro[i][j] == NAVIO) printf("3 ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("5 ");
        }
        printf("\n");
    }
}

// Cria matriz Cone (5x5)
void criarCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB/2 - i) && j <= (TAM_HAB/2 + i)) cone[i][j] = 1;
            else cone[i][j] = 0;
        }
    }
}

// Cria matriz Cruz (5x5)
void criarCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB/2 || j == TAM_HAB/2) cruz[i][j] = 1;
            else cruz[i][j] = 0;
        }
    }
}

// Cria matriz Octaedro (5x5)
void criarOctaedro(int octaedro[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB/2) + abs(j - TAM_HAB/2) <= TAM_HAB/2) octaedro[i][j] = 1;
            else octaedro[i][j] = 0;
        }
    }
}

// Sobrepõe matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int offset = TAM_HAB / 2; // deslocamento para centralizar
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha + (i - offset);
                int coluna = origemColuna + (j - offset);
                // valida limites
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == AGUA) {
                        tabuleiro[linha][coluna] = HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posiciona alguns navios fixos para visualização
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[5][5] = NAVIO;
    tabuleiro[6][5] = NAVIO;
    tabuleiro[7][5] = NAVIO;

    // Matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicar habilidades em pontos de origem
    aplicarHabilidade(tabuleiro, cone, 1, 1);       // cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);  // octaedro no canto inferior direito

    // Exibir tabuleiro final com cabeçalho
    exibirTabuleiro(tabuleiro);

    return 0;
}
