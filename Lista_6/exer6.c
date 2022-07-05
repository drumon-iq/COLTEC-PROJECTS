#include <stdio.h>

int main(){
	int inp;
	int cont = 0;
	int soma = 0;
	while(1){
		printf("Digite o valor a ser somado:\n");
		scanf("%d",&inp);
		cont++;
		soma+=inp;

		if(cont==10)
			break;
	}	
	printf("Soma: %d",soma);
}
