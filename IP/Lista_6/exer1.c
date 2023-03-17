#include <stdio.h>

int main(){
	int inp=0;

	do{
		printf("Digite um numero positivo: \n");
		scanf("%d",&inp);
	}while(inp <= 0);
	
	printf("Sequencia de pares de %d ate 0:", inp);

	for(inp; inp>=0; inp-=2){
		printf(" %d",inp);
	}	
	printf("\n");
}
