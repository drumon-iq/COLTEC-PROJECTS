#include <stdio.h>

int main(){

	float grms, final;
	int sec=0;

	printf("Digite a massa inicial em gramas:\n");
	scanf("%f",&grms);
	final = grms;
	while(final>0.5){
		final/=2;
		sec+=50;
	}
	printf("Massa inicial: %f\n", grms);
	printf("Massa final: %f\n", final);
	printf("Tempo para que a massa seja menor que 0,5 gramas: %d segundos\n",sec);

}
