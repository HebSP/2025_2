//
// Created by hsp2 on 11/26/25.
//

#ifndef INC_2025_2_LISTADUPLAENCADEADA_H
#define INC_2025_2_LISTADUPLAENCADEADA_H

typedef struct NoDuplo {
    int dado;
    struct NoDuplo* proximo;
    struct NoDuplo* anterior;
} NoDuplo;

typedef struct ListaDuplaEncadeada {
    NoDuplo* inicio;
    NoDuplo* fim;
    int tamanho;
} ListaDuplaEncadeada;


#endif //INC_2025_2_LISTADUPLAENCADEADA_H