#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sTentativa{
	char palavra[100];
	char simOuNao[5];
}tentativa;

int validaPalavra(char palavra[], int size_pal, char last_char, int tot_pal, tentativa *);

int main()
{

	tentativa *lista_pal = (tentativa*) malloc(5*sizeof(tentativa));

	int qntd_erro=0, size_pal=0, total_pal=0, win=0;
	char user[100], last_char = '\0';

	printf("Bem vindo ao Piquenique na Lua\n");
	printf("Digite o nick do jogador:\n");

	fgets(user, 94, stdin);
	for (int i = 0; '\0' != user[i]; ++i){
		if (user[i] == '\n' ){
			user[i] = '\0';
		}
	}

	FILE *history;

	strcat(user, ".dat");
	history = fopen(user, "w+");

	if(history == NULL) {
		printf("Nao foi possivel abrir o arquivo de dados, bailling out\n");
		return -1;
	}

	fprintf(history, "Acertos do jogo :\n=============================================");

	printf("\n================REGRAS==================\n");
	printf("Digite o nome do item que quer levar ao piquinique\n");
	printf("Com base em criterios secretos, te direi se pode leva-lo ou nao\n");
	printf("Se ganha ao acertar 5 palavras consecutivamente\n");
	printf("Caso voce erre 30 vezes ao todo voce perde\n");
	printf("Digite h para consultar o seu historico de tentativas.\n");
	printf("Digite q para sair.\n");
	printf("\n=====<>=====<>=====<>=====<>=====<>=====\n");

	while(win==0){
		if(strcmp(lista_pal[total_pal-4].simOuNao,"sim")==0 && strcmp(lista_pal[total_pal-5].simOuNao,"sim")==0 && strcmp(lista_pal[total_pal-1].simOuNao,"sim")==0 && strcmp(lista_pal[total_pal-2].simOuNao,"sim")==0 && strcmp(lista_pal[total_pal-3].simOuNao,"sim")==0){
			printf("\n=====<>=====<>=====<>=====<>=====<>=====\n");
			printf("Voce ganhou o jogo!!!\n");
			win = 1;
			break;
		}

		if(qntd_erro == 30){
			printf("\n=====<>=====<>=====<>=====<>=====<>=====\n");
			printf("Voce chegou a 30 erros, voce perdeu!\n");
			win = -1;
			break;
		}

		printf("Digite a palavra:\n");
		fgets(lista_pal[total_pal].palavra, 99, stdin);

		for(int a=0; a < strlen(lista_pal[total_pal].palavra) ; a++) {

			if(lista_pal[total_pal].palavra[a] == '\n'){
				lista_pal[total_pal].palavra[a] = '\0';
			}

			if(lista_pal[total_pal].palavra[a] >= 65 && lista_pal[total_pal].palavra[a] <= 90){
				lista_pal[total_pal].palavra[a] += 32;
			}
		}

		if ( lista_pal[total_pal].palavra[0] == 'q' ){
			win = -1;
		}

		else if ( lista_pal[total_pal].palavra[0] == 'h'){
			printf("\n=========HISTORICO DE TENTATIVAS========\n");

			for (int i = 0; i < total_pal; ++i){
				printf("Item tentada: %s\n", lista_pal[i].palavra);
				printf("Pode ser levado? %s\n\n", lista_pal[i].simOuNao);
			}

			printf("\n=====<>=====<>=====<>=====<>=====<>=====\n");
		}

		else{

			size_pal = strlen(lista_pal[total_pal].palavra);

			last_char = lista_pal[total_pal].palavra[size_pal-1];

			if(validaPalavra(lista_pal[total_pal].palavra, size_pal, last_char, total_pal, lista_pal) == 1){

				printf("Correto! %s pode ser levado!\n", lista_pal[total_pal].palavra);
				printf("Voce ainda tem %d tentativas!\n\n", 30-qntd_erro);

				strcpy(lista_pal[total_pal].simOuNao, "sim");

				fprintf(history, "\n%s", lista_pal[total_pal].palavra);

			} else {

				qntd_erro++;
				printf("Errado! %s nao pode ser levado!\n", lista_pal[total_pal].palavra);
				printf("%d tentativas restantes.\n\n", 30-qntd_erro);

				strcpy(lista_pal[total_pal].simOuNao, "nao");

			}

			total_pal++;
			lista_pal = (tentativa*) realloc(lista_pal, (total_pal+5)*sizeof(tentativa));
		}
	}

	free(lista_pal);
	fclose(history);

	return 0;

}

int validaPalavra(char palavra[], int size_pal, char last_char, int tot_pal, tentativa *lista_pal)
{

	for(int i=0; i<(tot_pal-1); ++i) {
		if(strncmp(lista_pal[tot_pal].palavra, lista_pal[i].palavra, size_pal) == 0 && tot_pal != 0) {

			printf("Palavra repetida\n");
			return 0;
		}
	}

	if(palavra[0]=='a'){
		return 1;
	}
	else if(palavra[size_pal-1]=='r'){
		return 1;
	}
	else if(palavra[0]==last_char){
		return 1;
	}
	else if(size_pal==10){
		return 1;
	}
	else if(strncmp("certamente eh", palavra, 13) == 0) {
		return 1;
	}
	else{
		return 0;
	}
}
