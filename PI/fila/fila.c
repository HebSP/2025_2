#include <stdio.h>
#include <stdlib.h>
#include <stllib.h>
#include "fila.h"

void inicializa(Fila *f) {
    f->front = 0;
    f->rear = 0;
    f->size = 0;
}

int isEmpty(Fila *f) {
    return f->size == 0;
}

int isFull(Fila *f) {
    return f->size == MAX;
}

int enqueue(Fila *f, int valor) {
    if (isFull(f)) {
        return 0; // Fila cheia
    }
    f->dados[f->rear] = valor;
    f->rear = (f->rear + 1) % MAX;
    f->size++;
    return 1; // Sucesso
}

int dequeue(Fila *f, int *valor) {
    if (isEmpty(f)) {
        return 0; // Fila vazia
    }
    *valor = f->dados[f->front];
    f->front = (f->front + 1) % MAX;
    f->size--;
    return 1; // Sucesso
}

int front(Fila *f) {
    if (isEmpty(f)) {
        printf("Fila vazia\n");
        exit(EXIT_FAILURE);
    }
    return f->dados[f->front];
}