#include <stdio.h>
#include <string.h>

int main(void){

	char nome[50], sobNome[50];

	printf("Digite o nome:\n");
	fgets(nome, 49, stdin);
	printf("Digite o sobrenome:\n");
	fgets(sobNome, 49, stdin);

	for(int i=0; i<50; i++){
		if(nome[i] == 10){
			nome[i] = 32;
			break;
		}
	}
	strcat( nome, sobNome);

	printf("Nome completo : %s", nome);

}
