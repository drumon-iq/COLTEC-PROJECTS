#include <stdio.h>
#include <string.h>

int main(void){

	char str1[50], str2[50];
	int res;

	printf("Digite a primeira string:\n");
	fgets(str1, 49, stdin);
	printf("Digite a segunda string:\n");
	fgets(str2, 49, stdin);

	res = strcmp(str1, str2);

	if(res == 0){
		printf("As strings são iguais.");
	}
	else{
		printf("As strings são diferentes.");
	}

}
