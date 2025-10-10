#include <stdio.h>
#include <string.h>

int main() {
    int n, x = 0;
    float p, t, g, nota, maiorNota = 0;
    scanf("%d", &n);
    char *nome = "", *maiorNome = "";
    for (int i = 0; i < n; i++) {
        scanf("%s %f %f %f", nome, &p, &t, &g);
        nota = (3 * p + g + 2 * t)/6;
        if (nota > maiorNota && nota >= 3.5) {
            maiorNota = nota;
            strcpy(maiorNome, nome);
            x++;
        }
    }
    printf("Temos %d lugares pra visitar!", x);
    if (maiorNota < 3.5) {
        printf("Puts. Melhor ficar em casa mesmo");
    } else {
        printf("Mais de sistema");
        printf("Devo começar por %s", maiorNome);
    }
}
