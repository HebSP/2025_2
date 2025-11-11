#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s = 0;
struct sinal{
    int amplitude;
    int frequencia;
    float energia;
    int periodico;
    int vitorias;
    int ptsmax;
};

struct sinal* insinais(){
    int amplitude, frequencia;
    float energia;
    char periodico[5];

    struct sinal* sinais = NULL;

    while (scanf("%d %d %f %s", &amplitude , &frequencia, &energia, &periodico) != EOF) {
        struct sinal sinal;
        sinal.amplitude = amplitude;
        sinal.frequencia = frequencia;
        sinal.energia = energia;
        sinal.periodico = strcmp(periodico,"TRUE");
        sinal.vitorias = 0;
        sinal.ptsmax = 0;
        sinais = realloc(sinais,sizeof(struct sinal)*(s+1));
        sinais[s++] = sinal;
    }
    return sinais;
}


int main(){
    struct sinal* sinais = insinais();

    for (int i = 1; i < s; i++) {
        int ptsp = (sinais[0].amplitude> sinais[i].amplitude)+(sinais[0].frequencia%sinais[i].frequencia==0) + (sinais[0].energia>sinais[i].energia) + (sinais[0].periodico>sinais[i].periodico),
            ptsi = (sinais[i].amplitude> sinais[0].amplitude)+(sinais[i].frequencia%sinais[0].frequencia==0) + (sinais[i].energia>sinais[0].energia) + (sinais[i].periodico>sinais[0].periodico);
        ptsp > ptsi?sinais[0].vitorias++ : sinais[i].vitorias++;
        if (sinais[0].ptsmax<ptsp) sinais[0].ptsmax = ptsp;
        sinais[i].ptsmax = ptsi;
    }
    printf("%d %d %.2f %d", sinais[0].amplitude, sinais[0].frequencia, sinais[0].energia, sinais[0].ptsmax);
    if (sinais[0].vitorias) {
        printf(" WINNER ( ");
        for (int i = 1; i< s; i++) if (!sinais[i].vitorias) printf("%d ", i);
        printf(")");
    }
    printf("\n---\n");
    for (int i = 1; i< s; i++) printf("%d %d %.2f %d%s\n", sinais[i].amplitude, sinais[i].frequencia, sinais[i].energia, sinais[i].ptsmax, sinais[i].vitorias?" WINNER":"");
    if (sinais[0].vitorias == s-1) printf("FLAWLESS VICTORY!\n");
    free(sinais);
    return 0;
}