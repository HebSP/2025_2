#include <stdlib.h>
#include <stdio.h>
#include "listaduplaencadeada.h"

void inicializa_lista(ListaDuplaEncadeada* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}
int lista_vazia(ListaDuplaEncadeada* lista) {
    return lista->inicio == NULL;
}

void insere_inicio(ListaDuplaEncadeada* lista, int valor) {
    NoDuplo* novo_no = (NoDuplo*)malloc(sizeof(NoDuplo));
    novo_no->dado = valor;
    novo_no->anterior = NULL;
    novo_no->proximo = lista->inicio;

    if (lista_vazia(lista)) {
        lista->fim = novo_no;
    } else {
        lista->inicio->anterior = novo_no;
    }
    lista->inicio = novo_no;
    lista->tamanho++;
}
void remove_inicio(ListaDuplaEncadeada* lista) {
    if (lista_vazia(lista)) {
        return;
    }
    NoDuplo* temp = lista->inicio;
    lista->inicio = lista->inicio->proximo;

    if (lista->inicio != NULL) {
        lista->inicio->anterior = NULL;
    } else {
        lista->fim = NULL;
    }

    free(temp);
    lista->tamanho--;
}
void libera_lista(ListaDuplaEncadeada* lista) {
    while (!lista_vazia(lista)) {
        remove_inicio(lista);
    }
}
void remove_fim(ListaDuplaEncadeada* lista) {
    if (lista_vazia(lista)) {
        return;
    }
    NoDuplo* temp = lista->fim;
    lista->fim = lista->fim->anterior;

    if (lista->fim != NULL) {
        lista->fim->proximo = NULL;
    } else {
        lista->inicio = NULL;
    }

    free(temp);
    lista->tamanho--;
}
void insere_fim(ListaDuplaEncadeada* lista, int valor) {
    NoDuplo* novo_no = (NoDuplo*)malloc(sizeof(NoDuplo));
    novo_no->dado = valor;
    novo_no->proximo = NULL;
    novo_no->anterior = lista->fim;
    if (lista_vazia(lista)) {
        lista->inicio = novo_no;
    } else {
        lista->fim->proximo = novo_no;
    }
    lista->fim = novo_no;
    lista->tamanho++;
}

