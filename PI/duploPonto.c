#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz_denteada(int linhas, int *tamanhos_colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        return NULL; // Falha na alocação
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(tamanhos_colunas[i] * sizeof(int));
        if (matriz[i] == NULL) {
            // Falha na alocação, liberar memória já alocada
            while (i--) {free(matriz[i]);}
            free(matriz);
            return NULL;
        }
    }

    return matriz;
}

void libera_matriz_denteada(int **matriz, int linhas) {
    while (linhas--) free(matriz[linhas]);
    free(matriz);
}

int main() {
    return 0;
}