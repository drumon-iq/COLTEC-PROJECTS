#include <stdio.h>

int main(void){

	char str[500];
	int i=0;

	printf("Digite a string:\n");
	fgets(str, 499, stdin);
// Apenas calcular com base no final da string não seria o suficiente pois também contaria com o ENTER, logo o loop deve parar no ENTER
	while(str[i] != 10){
		i++;
	}

	printf("Tamanho da string: %d", i);
}
