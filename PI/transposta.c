#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4
void lermatrz(int mtz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        scanf("%d %d %d %d", &mtz[i][0], &mtz[i][1], &mtz[i][2], &mtz[i][3]);
    }
}
void transposta(int mtz[TAM][TAM],int mtzt[TAM][TAM]) {

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            mtzt[i][j] = mtz[j][i];
        }
    }
}

void printmtz(int mtz[TAM][TAM]) {
    printf("Transposta\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", mtz[i][j]);
        }
        printf("\n");
    }
}


int main() {
    //int mtz[TAM][TAM] = {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
    int mtz[TAM][TAM], mtzt[TAM][TAM];
    lermatrz(mtz);
    transposta(mtz,mtzt);
    printmtz(mtzt);
    return 0;
}