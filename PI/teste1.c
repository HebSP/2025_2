#include <stdio.h>

int calcularC(int numero[100],int n){
    int c = 0;
    for(int i = 0; i<n ; i++){
        c += numero[i]*(1+2*(i%2==0));
    }
    return c%10;
}

int calcularR(int numero[100],int n){
    int r = 0;
    int s = 1;
    for(int i = 1; i<n; i++){
        if(numero[i-1] == numero[i]){
        s +=1;
        }else {
            if(s>r) r = s;
            s = 1;
        }
    }
    if (s>r) r=s;
    return r;
}

void gerarPalavra(char palavra[100],char basesaida[100]){
    int pulos = 0;
    for(int i = 0; palavra[i] != '\0'; i++){
        switch(palavra[i]) {
            case 'B': case 'b': basesaida[i-pulos] = 'B'; break;
            case 'C': case 'c': basesaida[i-pulos] = 'C'; break;
            case 'D': case 'd': basesaida[i-pulos] = 'D'; break;
            case 'F': case 'f': basesaida[i-pulos] = 'F'; break;
            case 'G': case 'g': basesaida[i-pulos] = 'G'; break;
            case 'H': case 'h': basesaida[i-pulos] = 'H'; break;
            case 'J': case 'j': basesaida[i-pulos] = 'J'; break;
            case 'K': case 'k': basesaida[i-pulos] = 'K'; break;
            case 'L': case 'l': basesaida[i-pulos] = 'L'; break;
            case 'M': case 'm': basesaida[i-pulos] = 'M'; break;
            case 'N': case 'n': basesaida[i-pulos] = 'N'; break;
            case 'P': case 'p': basesaida[i-pulos] = 'P'; break;
            case 'Q': case 'q': basesaida[i-pulos] = 'Q'; break;
            case 'R': case 'r': basesaida[i-pulos] = 'R'; break;
            case 'S': case 's': basesaida[i-pulos] = 'S'; break;
            case 'T': case 't': basesaida[i-pulos] = 'T'; break;
            case 'V': case 'v': basesaida[i-pulos] = 'V'; break;
            case 'W': case 'w': basesaida[i-pulos] = 'W'; break;
            case 'X': case 'x': basesaida[i-pulos] = 'X'; break;
            case 'Y': case 'y': basesaida[i-pulos] = 'Y'; break;
            case 'Z': case 'z': basesaida[i-pulos] = 'Z'; break;
            default: pulos++; break;
        }
    }
    if (basesaida[0] == '\0'){
        basesaida[0] ='V';
        basesaida[1] ='O';
        basesaida[2] ='I';
        basesaida[3] ='D';
        basesaida[4] ='\0';
    }

}

int main(){
    int n, numero[100];
    scanf("%d",&n);
    char charnum[100], palavra[100];
    scanf("%s", &charnum);
    scanf("%s",&palavra);
    for(int i = 0; charnum[i] != '\0'; i++) {
        numero[i] = charnum[i] -48;
    }
    int c = calcularC(numero,n);
    int r = calcularR(numero,n);
    char basesaida[100] = "";
    gerarPalavra(palavra, basesaida);

    printf("%d %d\n", c, r);
    printf("codigo: %s%d%d", basesaida, c, r);
    return 0;
}
