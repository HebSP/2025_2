#include <stdio.h>
#include <stdlib.h>

struct sinal{
    int amplitude;
    int frequencia;
    float energia;
    int periodico;
};

struct sinal* insinais(){

    sinal* ptr = (sinal*) malloc(sizeof(struct sinal));
    return ptr;
}


int main(){
    struct sinal princesa;
    princesa.amplitude=10;
    struct sinal* inimigos = insinais();

        (struct sinal*) malloc(3 * sizeof(struct sinal));
    return 0;
}