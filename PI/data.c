#include <stdio.h>

int main() {
	int dia, mes, ano;
	scanf("%d %d %d", &dia, &mes, &ano);
	int valido = (dia>0&& ano>0) && ((32>dia && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)) || (31>dia && (mes==4 || mes==6 || mes==9 || mes==11)) || (30>dia && mes==2 && !(ano%4) && ((ano%100) || !(ano%400)) ) || (29>dia && mes==2 ));
	printf("%svalida\n", valido?"":"in");
	return 0;
}