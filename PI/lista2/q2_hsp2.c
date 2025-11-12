
#include <stdio.h>

int main() {
    int vet[5] = {1,2,3,4,5};
    int* p = vet;
    printf("endereço em vet: %p, endereço em p: %p\n", vet, p);
    for (int i = 0; i < 5; i++) printf("p[%d] = %d, *(p + %d) = %d\n", i, p[i], i, *(p + i));
    for (int i = 0; i < 5; i++) printf("vet[%d] = %d, *(vet + %d) = %d\n", i, vet[i], i, *(vet + i));
    return 0;
}
