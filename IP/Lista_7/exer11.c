#include <stdio.h>

int main(void){

	char str[50];
	int count=0;

	printf("Digite a string:\n");
	fgets(str, 49, stdin);

	for(int i=0; str[i] != '\0'; i++){
		switch(str[i]){
			case 'A':
				count++;
				break;
			case 'E':
				count++;
				break;
			case 'I':
				count++;
				break;
			case 'O':
				count++;
				break;
			case 'U':
				count++;
				break;
			case 'a':
				count++;
				break;
			case 'e':
				count++;
				break;
			case 'i':
				count++;
				break;
			case 'o':
				count++;
				break;
			case 'u': 
				count++;
				break;

		}
	}

	printf("Quantidade de vogais: %d", count);
}
