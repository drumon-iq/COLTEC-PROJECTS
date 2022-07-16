#include <stdio.h>

int main(){
	
	int vetA[4], vetB[4], vetC[8];

	printf("Digite o vetor A com 4 elementos:\n");
	for(int i=0;i<4;i++){
		scanf("%d",&vetA[i]);	
		vetC[i] = vetA[i];
	}	

	printf("Digite o vetor B com 4 elementos:\n");
	for(int i=0;i<4;i++){
		scanf("%d",&vetB[i]);	
		vetC[i+4] = vetB[i];
	}

	printf("Vetor C:\n");

	for(int i=0;i<8;i++){
		printf(" %d",vetC[i]);
	}
}

