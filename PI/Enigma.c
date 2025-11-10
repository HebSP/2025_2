#include <stdio.h>
#include <string.h>

int main() {
    char letras[52] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };

    char message[50] = "";
    int c;
    scanf("%d", &c);
    c = c % 52;
    scanf(" %[^\n]%*c", message);

    while (strcmp(message, "FIM") != 0) {
        int espacos = 0;
        for (int i = 0; message[i] != '\0'; i++) {
            if (message[i] == ' ') {
                printf(" ");
                espacos++;
                continue;
            }
            for (int j = 0; j < 52; j++) {
                if (message[i] == letras[j]) {
                    int indce = (j - c - 1 - i + espacos);
                    while (indce < 0) indce += 52;
                    indce = indce % 52;
                    printf("%c", letras[indce]);
                    break;
                }
                if (j == 51) {
                    printf("%c", message[i]);
                }
            }
        }
        printf("\n");
        scanf("%[^\n]%*c", message);
    }

    return 0;
}