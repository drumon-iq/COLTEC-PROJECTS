#include <stdio.h>

int main(void){

	char str[50];
	int num;

	printf("Digite uma string:\n");
	fgets(str, 49, stdin);
	printf("Digite um numero:\n");
	scanf("%d",&num);
	printf("%d primeiros caracteres da string: ",num);

	for(int i=0; i<num; i++){
		printf("%c",str[i]);
	}

}
