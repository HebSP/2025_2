
#include <stdio.h>

int main() {
    char c = 'a';
    char* pc = &c;
    printf("endereço de c: %p valor de c: %c\n", (void*)&c, c);
    printf("valor de pc: %p, valor apontado por pc: %c\n", pc, *pc);
    printf("endereço de pc: %p\n", (void*)&pc);
    printf("O endereço do valor guardado no endereço apontado por pc: %p, o valor guardado no endereço de pc %p\n", &*pc, (void*)&pc);
    printf(("esses valores são iguais porque o valor guardado em pc é o endereço de c, e o valor guardado no endereço de pc é exatamente esse endereço de c\n"));

    return 0;
}
