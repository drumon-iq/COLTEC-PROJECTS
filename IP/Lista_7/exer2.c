#include <stdio.h>

int main(){
	
	int vet[10];

	printf("Digite o vetor com 10 elementos:\n");

	for(int i=0; i<10; i++){
		scanf("%d",&vet[i]);
	}
	
	printf("Valores ímpares:");
	
	for(int i=0;i<10;i++){
		if(vet[i]%2==0)
			continue;
		printf(" %d",vet[i]);
	}
}

