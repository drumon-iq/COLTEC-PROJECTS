#include <stdio.h>

struct character {
	char name[20];
	int id, lvl, health, atk, def;
};

void main()
{
	int amount;

	printf("Digite a quantidade de personagens:\n");
	scanf(" %d", &amount);

	struct character characters[amount];
	for(int i=0; i<amount; i++) {
		getchar();
		printf("Digite o nome do personagem %d:\n", i+1);
		fgets(characters[i].name, 19, stdin);
		printf("Digite o ID do personagem %d:\n", i+1);
		scanf(" %d", &characters[i].id);
		printf("Digite o Level do personagem %d:\n", i+1);
		scanf(" %d", &characters[i].lvl);
		printf("Digite a quantidade de Vida do personagem %d:\n", i+1);
		scanf(" %d", &characters[i].health);
		printf("Digite o Ataque do personagem %d:\n", i+1);
		scanf(" %d", &characters[i].atk);
		printf("Digite a Defesa do personagem %d:\n", i+1);
		scanf(" %d", &characters[i].def);
	}

	for(int i=0; i<amount; i++) {
		printf("Nome: %s\n", characters[i].name);
		printf("ID: %d\n", characters[i].id);
		printf("Level: %d\n", characters[i].lvl);
		printf("Vida: %d\n", characters[i].health);
		printf("Ataque: %d\n", characters[i].atk);
		printf("Defesa: %d\n", characters[i].def);
	}
}
