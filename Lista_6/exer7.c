#include <stdio.h>

int main(){
	int inp, res;
	
	do{
		printf("Digite um numero não-negativo:\n");
		scanf("%d",&inp);
		if(inp<0)
			printf("Numero deve ser maior ou igual a 0\n");
	}while(inp<0);
	
	if(inp!=0){
		res = inp;
		for(int i=1; i<inp;i++)
			res*=i;
		printf("Fatorial de %d: %d\n",inp, res);
	}else{
		printf("Fatorial de 0: 1\n");
	}
}
