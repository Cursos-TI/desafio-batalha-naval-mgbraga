#include <stdio.h>

int main() {

    int tabuleiro[10][10];
    int linha, coluna;

    // Inicializa o tabuleiro com 0 (água)
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Cria os navios
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3]   = {3, 3, 3};

    // Mostra os navios
    printf("Navio Horizontal: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", navio_horizontal[i]);
    }
    printf("\n");

    printf("Navio Vertical:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\n", navio_vertical[i]);
    }
    printf("\n");

    // Coordenadas iniciais dos navios
    int linha_h = 2, coluna_h = 4; // navio horizontal
    int linha_v = 5, coluna_v = 7; // navio vertical

    // Validação de limites
    if (coluna_h + 3 > 10) {
        printf("Erro: navio horizontal ultrapassa o tabuleiro.\n");
        return 1;
    }
    if (linha_v + 3 > 10) {
        printf("Erro: navio vertical ultrapassa o tabuleiro.\n");
        return 1;
    }

    // Validação de sobreposição
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha_h][coluna_h + i] != 0) {
            printf("Erro: navio horizontal sobrepõe outro navio.\n");
            return 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha_v + i][coluna_v] != 0) {
            printf("Erro: navio vertical sobrepõe outro navio.\n");
            return 1;
        }
    }

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Imprime o tabuleiro
    printf("Tabuleiro (0 = água, 3 = navio):\n");
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
