#include <stdio.h>

int is_digit(char);

void main(void)
{
	char inp;
	int isChar;
	
	printf("Digite um caractere: \n");
	scanf(" %c", &inp);
	isChar = is_digit(inp);

	if(isChar==1)
		printf("O caractere e um digito \n");
	else
		printf("O caractere nao e um digito \n");
}

int is_digit(char test)
{
	if(test >= 48 && test <= 57)
		return 1;
	return 0;
}
