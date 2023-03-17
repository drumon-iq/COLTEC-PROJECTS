#include <stdio.h>
#include <string.h>

int main(void){

	char nome[51]="", optOut[51]="SAIR";

	while(strncmp(optOut, nome, 4) != 0){
		printf("Digite o nome:\n");
		fgets(nome, 50, stdin);
		printf("Nome digitado: %s\n", nome);
	}

}
