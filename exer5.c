
#include <stdio.h>
#include <stdlib.h>

int main(){

	int inp=102, luckNum=rand()%100,cont=0;

	while(inp != luckNum){
		printf("Qual o numero da sorte?\n");
		scanf("%d",&inp);
		
		if(inp == luckNum){
			printf("ACERTOU\n");
		}
		else if(inp>luckNum){
			printf("Não. Numero da sorte é menor.\n");
		}
		else{
			printf("Não. Numero da sorte é maior.\n");
		}
		cont++;
	}
	printf("Numero de tentativas: %d",cont);
}
