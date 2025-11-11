#include <stdio.h>
#define MAX 46342
int key(int n){

    int p[MAX] = {0};
    int r = 0;
    for (int i = 2; i*i < n && i < MAX; i++) if (!p[i]) {
        while (n%i==0){
            n/=i;
            r++;
        }
        for (int j = i*i; j*j<n && j < MAX; j+=i) p[j]=1;
    }
    return r + (n>1);
}

void decode(char entrada[],int key){
    char letras[52] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    int espacos = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        int j, maiu = 0, skip = 0;

        switch (entrada[i]){
            case 'A': maiu++; case 'a': j = 0; break;
            case 'B': maiu++; case 'b': j = 1; break;
            case 'C': maiu++; case 'c': j = 2; break;
            case 'D': maiu++; case 'd': j = 3; break;
            case 'E': maiu++; case 'e': j = 4; break;
            case 'F': maiu++; case 'f': j = 5; break;
            case 'G': maiu++; case 'g': j = 6; break;
            case 'H': maiu++; case 'h': j = 7; break;
            case 'I': maiu++; case 'i': j = 8; break;
            case 'J': maiu++; case 'j': j = 9; break;
            case 'K': maiu++; case 'k': j = 10; break;
            case 'L': maiu++; case 'l': j = 11; break;
            case 'M': maiu++; case 'm': j = 12; break;
            case 'N': maiu++; case 'n': j = 13; break;
            case 'O': maiu++; case 'o': j = 14; break;
            case 'P': maiu++; case 'p': j = 15; break;
            case 'Q': maiu++; case 'q': j = 16; break;
            case 'R': maiu++; case 'r': j = 17; break;
            case 'S': maiu++; case 's': j = 18; break;
            case 'T': maiu++; case 't': j = 19; break;
            case 'U': maiu++; case 'u': j = 20; break;
            case 'V': maiu++; case 'v': j = 21; break;
            case 'W': maiu++; case 'w': j = 22; break;
            case 'X': maiu++; case 'x': j = 23; break;
            case 'Y': maiu++; case 'y': j = 24; break;
            case 'Z': maiu++; case 'z': j = 25; break;
            case ' ': espacos++;
            default: printf("%c", entrada[i]); skip++; break;
        }
        if (skip) continue;
        int indce = (j + key + i - espacos)%26 + maiu*26;
        printf("%c", letras[indce]);
    }

}


int main(){
    int n, k;
    scanf("%d",&n);
    char sin[100],sou[100];
    scanf(" %[^\n]",sin);

    k = key(n);
    printf("%d\n", k);
    decode(sin,k);
    return 0;
}