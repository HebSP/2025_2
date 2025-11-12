//Faça um programa que aloque dinamicamente um vetor de strings str, receba de entrada várias strings enquanto existir
//entrada no buffer e guarde-as nesse vetor utilizando ponteiros auxiliares (ponteiro temporário na hora de dar realloc).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char** str = NULL;
    int lenStr = 0;
    char* buffer = NULL;
    int lenBuffer = 0;
    char aux = getchar();
    while (aux != EOF) {
        while (aux != '\n' && aux != EOF) {
            buffer = (char*) realloc(buffer, lenBuffer + 2);
            if (buffer == NULL) {
                printf("Erro de alocação\n");
                for (int i = 0; i < lenStr; i++) free(str[i]);
                free(str);
                return 1;
            }
            buffer[lenBuffer++] = aux;
            buffer[lenBuffer] = '\0';
            aux = getchar();
        }
        str = (char**) realloc(str, (lenStr + 1) * sizeof(char*));
        if (str == NULL) {
            printf("Erro de alocação\n");
            return 1;
        }
        str[lenStr] = (char*) malloc((lenBuffer + 1) * sizeof(char));
        strcpy(str[lenStr], buffer);
        free(buffer);
        buffer = NULL;
        lenBuffer = 0;
        lenStr++;
        aux = getchar();
    }

    //so pra ver que coletou os inputs corretamente
    printf("%d linhas\n", lenStr);
    for (int i = 0; i < lenStr; i++) {
        printf("%s\n", str[i]);
    }

    for (int i = 0; i < lenStr; i++) free(str[i]);
    free(str);
    return 0;
}