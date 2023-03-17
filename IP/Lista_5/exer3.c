#include <stdio.h>

int main(){

	int chosenOne, mult;

	do{

		printf("Digite um numero entre 1 e 50:\n");
		scanf("%d",&chosenOne);

		if(chosenOne >=1 && chosenOne<=50){
			mult = chosenOne;
			while(mult*3<250){
				mult*=3;
				printf("Multiplicado por 3: %d\n", mult);
			}
		}
		else{
			printf("Numero deve estar entre 1 e 50\n");
		}

	}while(!(chosenOne>=1 && chosenOne<=50));

}
