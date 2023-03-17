#include <stdio.h>

int main(){
	int inp, maior=0;

	for(int i=1; i<=10; i++){
		printf("Digite a idade da pessoa %d: \n",i);
		scanf("%d",&inp);
		if(inp>17){maior++;}
	}
	printf("Numero de pessoas com idade maior ou igual a 18 anos: %d\n", maior);
}
