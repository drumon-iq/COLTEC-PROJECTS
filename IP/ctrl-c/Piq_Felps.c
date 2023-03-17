#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sTentativa{
	char palavra[100];
	char simOuNao[5];
}tentativa;

void separador_de_linhas(){
	printf("----------------------------------------\n");
}

int validaPalavra(char palavra[], int tamanho, char anterior){
	if(palavra[0]=='a'){
		return 1;
	}
	else if(palavra[tamanho-1]=='r'){
		return 1;
	}
	else if(palavra[0]==anterior){
		return 1;
	}
	else if(tamanho==10){
		return 1;
	}
	else{
		return 0;
	}
}

void regras(){
	printf("-----------------REGRAS----------------\n");
	printf("Ola, vamos comecar a jogar\n");
	printf("Digite uma palavra e te direi se vc pode levar o que escreveu para o piquenique.\n");
	printf("Digite \"q\" para sair.\n");
	printf("Digite \"h\" para consultar o seu historico de tentativas.\n");
	printf("Digite \"r\" para poder dar uma olhada nas regras dnv\n");
	printf("Vc pode errar ate 30 vezes. Caso acerte 5 vezes seguidas, sera considerado vencedor!\n");
	printf("Lembrando apenas que so letras minusculas e palavras nao ascentuadas sao aceitas\n");
	separador_de_linhas();
}

int main(){
	tentativa *try;
	int erros=0, controle, tamanho=0, rodadas=0, maiuscula=0, n=0;
	char nome[21], anterior = '\0';
	FILE *fp;
	printf("Bem vindo ao Piquenique na Lua\n");
	printf("Antes de começarmos digite seu nome:");
	fgets(nome, 20, stdin);
	for (int i = 0; '\0' != nome[i]; ++i){
		if (nome[i] == '\n' ){
			nome[i] = '\0';
		}
	}
	try = (tentativa*) malloc(1*sizeof(tentativa));
	/*
	fp = fopen("%s.txt" nome, "w");
	fprintf(fp, "Esse e seu arquivo, onde sao registradas as suas tentativas corretas ao longo do jogo e que nao tenham palavras repetidas a outras ja usadas\n");
	*/
	regras();
	do{
		maiuscula = 0;
		n=0;
		if(strcmp(try[rodadas-1].simOuNao,"sim")==0 && strcmp(try[rodadas-2].simOuNao,"sim")==0 && strcmp(try[rodadas-3].simOuNao,"sim")==0){
			if(strcmp(try[rodadas-4].simOuNao,"sim")==0 && strcmp(try[rodadas-5].simOuNao,"sim")==0){
			    separador_de_linhas();
				printf("PARABENS!!! Voce ganhou\n");
				printf("Nao fez nada mais que o necessario\n");
				fclose(fp);
				return 0;
			}
		}

		if(erros == 30){
			separador_de_linhas();
			printf("Voce perdeu XD\n");
			fclose(fp);
			return 0;
		}

		printf("-->Digite uma palavra: ");
		fgets(try[rodadas].palavra, 99, stdin);

		do{
			if(try[rodadas].palavra[n] == '\0'){
				break;
			}
			if(try[rodadas].palavra[n] >= 65 && try[rodadas].palavra[n] <= 90){
				printf("Lembre-se que apenas letras minusculas sao aceitas\n\n");
				maiuscula = 1;
				break;
			}
			n++;
		}while(maiuscula==0);

		if(maiuscula == 1){
			continue;
		}

		else if (strcmp(try[rodadas].palavra,"q\n")==0){
			fclose(fp);
			return 0;
		}

		else if (strcmp(try[rodadas].palavra,"r\n")==0){
			regras();
		}

		else if (strcmp(try[rodadas].palavra,"h\n")==0){
			printf("----------HISTORICO DE TENTATIVAS----------\n");
			if(rodadas==0){
				printf("Voce ainda nao fez nenhuma tentativa\n");
			}
			else{
				for (int i = 0; i < rodadas; ++i){
					printf("Tentativa %d:\n", i+1);
					printf("Palavra tentada: %s", try[i].palavra);
					printf("Palavra aceita? %s\n\n", try[i].simOuNao);
				}
			}
			separador_de_linhas();
		}

		else{
			rodadas++;
			try = (tentativa*) realloc(try, rodadas*sizeof(tentativa));
			tamanho = strlen(try[rodadas-1].palavra)-1;
			controle = validaPalavra(try[rodadas-1].palavra, tamanho, anterior);
			anterior = try[rodadas-1].palavra[tamanho-1];
			if(controle == 1){
				printf("PARABENS! Voce pode levar %s", try[rodadas-1].palavra);
				printf("Voce ainda pode errar mais %d vezes.\n\n", 30-erros);
				strcpy(try[rodadas-1].simOuNao, "sim");
			}
			if(controle == 0){
				erros++;
				printf("%c\n", anterior);
				printf("Voce nao pode levar %s", try[rodadas-1].palavra);
				printf("Voce ainda pode errar mais %d vezes.\n\n", 30-erros);
				strcpy(try[rodadas-1].simOuNao, "nao");
			}
		}
	}while(1);
}