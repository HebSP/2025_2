#include <stdio.h>
#include <string.h>

int main() {
    int n, x = 0;
    float p, t, g, nota, maiorNota = 0;
    scanf("%d", &n);
    char nome[100] = "", maiorNome[100] = "";
    for (int i = 0; i < n; i++) {
        scanf("%s %f %f %f", nome, &p, &g, &t);
        nota = (3 * p + g + 2 * t)/6;
        if (nota>= 3.5) {
            if (nota > maiorNota) {
                maiorNota = nota;
                strcpy(maiorNome, nome);
            }
            x++;
        }
    }
    printf("Temos %d lugares pra visitar!\n", x);
    if (maiorNota < 3.5) {
        printf("Puts. Melhor ficar em casa mesmo");
    } else {
        printf("Devo comecar por %s", maiorNome);
    }
}
