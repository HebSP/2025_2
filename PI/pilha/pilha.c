#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


void inicializa(Pilha *p) {
    p->topo = -1;
}

int isempty(Pilha *p) {
    return p->topo == -1;
}

int isfull(Pilha *p) {
    return p->topo == max - 1;
}

int push(Pilha *p, int valor) {
    if (isfull(p)) {
        return 0; // Pilha cheia
    }
    p->dados[++(p->topo)] = valor;
    return 1; // Sucesso
}

int pop(Pilha *p, int *valor) {
    if (isempty(p)) {
        return 0; // Pilha vazia
    }
    *valor = p->dados[(p->topo)--];
    return 1; // Sucesso
}

int top(Pilha *p) {
    if (isempty(p)) {
        printf("Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    return p->dados[p->topo];
}


int main() {
    int n;
    long long int fat = 1;
    scanf("%d", &n);
    Pilha pilha;
    inicializa(&pilha);
    for (int i = 0; i < n; i++) push(&pilha, i+1);
    while (!isempty(&pilha)) {
        int valor;
        pop(&pilha, &valor);
        fat*= valor;
    }
    printf("%lld", fat);
    return 0;
}