#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int jog1=0, jog2=0;
	char esc;

	srand(time(NULL));

	printf("JOGADOR 1\n");
	do{
		jog1+= 1+(rand()%10);
		printf("soma = %d\n", jog1);
		printf("Deseja continuar? s ou n:\n");
		scanf(" %c",&esc);
	}while(esc!= 'n');

	printf("JOGADOR 2\n");
	do{
		jog2+= 1+(rand()%10);
		printf("soma = %d\n", jog2);
		printf("Deseja continuar? s ou n:\n");
		scanf(" %c",&esc);
	}while(esc!= 'n');
	
	if(jog1>21 && jog2>21){
		printf("EMPATE");
	}
	else if(jog1>21){
		printf("VENCEDOR: JOGADOR 2");
	}
	else if(jog2>21){
		printf("VENCEDOR: JOGADOR 1");
	}
	else if(jog1>jog2){
		printf("VENCEDOR: JOGADOR 1");
	}
	else if(jog1==jog2){
		printf("EMPATE");
	}
	else{
		printf("VENCEDOR: JOGADOR 2");
	}
	printf("\n\n");
}
