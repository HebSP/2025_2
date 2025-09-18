#include <stdio.h>

int main() {
    int q, r, s;

    scanf("%d %d %d", &q, &r, &s);
    int x = q + r * (s-1);
    printf("Na semana %d Soneca tera que fazer %d questoes!", s, x);
    return 0;
}