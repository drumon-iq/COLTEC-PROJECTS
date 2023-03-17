#include <stdio.h>

#define MAX_PLAYERS 20

struct player {
	char nome[50], posicao[50];
	int camisa;
	float altura, peso;
};

void main()
{
	struct player futeboleiros[MAX_PLAYERS];

	for(int i=0; i<MAX_PLAYERS; i++) {
		fflush(stdin);
		printf("Digite nome do jogador:\n");
		fgets(futeboleiros[i].nome, 49, stdin);
		printf("Digite numero da camisa:\n");
		scanf(" %d",&futeboleiros[i].camisa);
		printf("Digite peso (kg):\n");
		scanf(" %f",&futeboleiros[i].peso);
		printf("Digite altura (m):\n");
		scanf(" %f",&futeboleiros[i].altura);
		getchar();
		printf("Digite a posição:\n");
		fgets(futeboleiros[i].posicao, 49, stdin);
	}
	
	printf("Jogadores Titulares:\n");

	for(int i=0; i<MAX_PLAYERS; i++) {
		if(futeboleiros[i].camisa >= 1 && futeboleiros[i].camisa <=11)
			printf("%s", futeboleiros[i].nome);
	}
}
