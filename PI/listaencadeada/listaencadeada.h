//
// Created by hsp2 on 11/26/25.
//

#ifndef INC_2025_2_LISTAENCADEADA_H
#define INC_2025_2_LISTAENCADEADA_H

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct ListaEncadeada {
    No* inicio;
    int tamanho;
} ListaEncadeada;

#endif //INC_2025_2_LISTAENCADEADA_H