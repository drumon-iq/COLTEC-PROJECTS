#include <stdio.h>
#define MAX_ASSOCIADOS 50

typedef struct dados {
	char endereco[50];
	int telefone;
	int dia, mes, ano;	
};

typedef struct dados dados;

struct associado {
	char nome[50];
	int carteira;
	dados human;
};

int anos(int dia, int mes, int ano);

void main()
{
	char resposta='s';
	struct associado Contas[MAX_ASSOCIADOS];
	int i=0;

	while(resposta == 's' && i<50) {
		printf("Digite nome do associado:\n");
		fgets(Contas[i].nome, 49, stdin);
		printf("Digite numero da carteira do associado:\n");
		scanf("%d", &Contas[i].carteira);
		printf("Digite endereco do associado:\n");
		getchar();
		fgets(Contas[i].human.endereco, 49, stdin);
		printf("Digite telefone do associado:\n");
		scanf("%d", &Contas[i].human.telefone);
		printf("Digite dia, mes e ano de nascimento do associado:\n");
		scanf("%d", &Contas[i].human.dia);
		scanf("%d", &Contas[i].human.mes);
		scanf("%d", &Contas[i].human.ano);
		printf("Deseja inserir outro associado:\n");
		scanf(" %c", &resposta);

		i++;
	}

	printf("Associados:\n");
	i--;
	for(i; i>=0; i--) {
		printf("%d\n\n", i);
		printf("%s", Contas[i].nome); 
		printf(" %d anos\n", anos(Contas[i].human.dia, Contas[i].human.mes, Contas[i].human.ano)); 
	}                                                  
}                                                          

int anos(int dia, int mes, int ano)
{
	int dAtual = 2022*365 + 9*30 + 17;
	int age, difer;

	dia += ano*365;
	dia += mes*30;

	difer = dAtual - dia;
	age = difer/365;

	return age;
}
