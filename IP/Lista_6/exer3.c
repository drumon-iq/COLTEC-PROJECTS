#include <stdio.h>

int main(){
	int inp;
	printf("Digite um numero: \n");
	scanf("%d",&inp);

	printf("Tabuada de %d:\n", inp);
	for(int i=1;i<=9;i++){
		printf("%d x %d = %d \n",inp,i,inp*i);
	}
}
