#include <stdio.h>

struct Atleta {
	char nome[50];
	char esporte[50];
	int idade;
	float altura;
};

void main()
{
	struct Atleta steve[3];
	int mAlto;
	int mVelho;

	for(int i=0; i<3; i++) {
		printf("Digite o nome do atleta %d:\n", i+1);
		fgets(steve[i].nome, 49, stdin);
		printf("Digite o esporte do atleta %d:\n", i+1);
		fgets(steve[i].esporte, 49, stdin);
		printf("Digite a idade do atleta %d:\n", i+1);
		scanf("%d", &steve[i].idade); 
		printf("Digite a altura do atleta %d:\n", i+1);
		scanf("%f", &steve[i].altura); 
		getchar();
	}

	mAlto = 0;
	mVelho = 0;

	for(int i=1; i<3; i++) {
		if(steve[i].altura > mAlto)
			mAlto = i;
		if(steve[i].idade > mVelho)
			mVelho = i;
	}

	printf("Atleta mais alto: %s\n", steve[mAlto].nome);
	printf("Atleta mais velho: %s\n", steve[mVelho].nome);
}
