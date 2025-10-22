#include <stdio.h>

void* memsrch(void *bloco, size_t tamanho_bloco, void *sub_bloco, size_t tamanho_sub_bloco) {
    unsigned char *b = (unsigned char *)bloco;
    unsigned char *s = (unsigned char *)sub_bloco;

    if (tamanho_sub_bloco == 0 || tamanho_bloco < tamanho_sub_bloco) {
        return NULL;
    }

    for (size_t i = 0; i <= tamanho_bloco - tamanho_sub_bloco; i++) {
        size_t j;
        for (j = 0; j < tamanho_sub_bloco; j++) {
            if (b[i + j] != s[j]) {
                break;
            }
        }
        if (j == tamanho_sub_bloco) {
            return (void *)(b + i);
        }
    }
    return NULL;
}

int main() {

    void* teste = memsrch("texto", 5, "xto", 3);
    if (teste != NULL) {
        printf("Substring encontrada: %s\n", (char*)teste);
    } else {
        printf("Substring nao encontrada\n");
    }
    return 0;
}