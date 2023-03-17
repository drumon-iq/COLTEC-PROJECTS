#include <stdio.h>

int main(){

	float vet[7], soma=0;
	
	printf("Digite o vetor com 7 elementos reais:\n");
	
	for(int i=0; i<7; i++){
		scanf("%f",&vet[i]);
		soma+=vet[i];
	}
	
	printf("Soma dos valores: %.2f", soma);
	
}

