#include <stdlib.h>
#include <stdio.h>
#include "listaencadeada.h"


void inicializa_lista(ListaEncadeada* lista) {
    lista->inicio = NULL;
}

int lista_vazia(ListaEncadeada* lista) {
    return lista->inicio == NULL;
}

void insere_inicio(ListaEncadeada* lista, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->dado = valor;
    novo_no->proximo = lista->inicio;
    lista->inicio = novo_no;
    lista->tamanho++;
}

void remove_inicio(ListaEncadeada* lista) {
    if (lista_vazia(lista)) {
        return;
    }
    No* temp = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    lista->tamanho--;
    free(temp);
}

void libera_lista(ListaEncadeada* lista) {
    while (!lista_vazia(lista)) {
        remove_inicio(lista);
        lista->tamanho--;
    }
}

void remove_fim(ListaEncadeada* lista) {
    if (lista_vazia(lista)) {
        return;
    }
    if (lista->inicio->proximo == NULL) {
        free(lista->inicio);
        lista->inicio = NULL;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo->proximo != NULL) atual = atual->proximo;

        free(atual->proximo);
        atual->proximo = NULL;
    }
    lista->tamanho--;
}

void insere_fim(ListaEncadeada* lista, int valor) {
    if (lista_vazia(lista)) {
        insere_inicio(lista, valor);
    } else {
        No* novo_no = (No*)malloc(sizeof(No));
        novo_no->dado = valor;
        novo_no->proximo = NULL;

        No* atual = lista->inicio;
        while (atual->proximo != NULL) atual = atual->proximo;

        atual->proximo = novo_no;
        lista->tamanho++;
    }
}

int tamanho_lista(ListaEncadeada* lista) {
    return lista->tamanho;
}

No* busca_elemento(ListaEncadeada* lista, int valor) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dado == valor) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void imprime_lista(ListaEncadeada* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}