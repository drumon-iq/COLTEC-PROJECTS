#include <stdio.h>

void para_maiuscula(char *help);

void main(void)
{
	char string[50];

	printf("Digite uma string: \n");
	fgets(string, 49, stdin);
	printf("String Maiuscula: ");
	para_maiuscula(string);
}

void para_maiuscula(char *string)
{
	for(int i=0; i<50; i++){
		if(string[i] >= 97 && string[i] <= 122)
			string[i]-=32;
	}
	
	printf("%s", string);
}
