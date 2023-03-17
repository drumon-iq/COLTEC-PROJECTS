#include <stdio.h>

int main(){
	
	int vetA[6], vetB[6], vetC[6];

	printf("Digite o vetor A com 6 elementos:\n");
	for(int i=0;i<6;i++){
		scanf("%d",&vetA[i]);	
	}	

	printf("Digite o vetor B com 6 elementos:\n");
	for(int i=0;i<6;i++){
		scanf("%d",&vetB[i]);	
	}

	printf("Vetor C:\n");

	for(int i=0;i<6;i++){
		vetC[i]= vetA[i] - vetB[i];
		printf(" %d",vetC[i]);
	}
}

