#include <stdio.h>

int main(void){

	char str[50];
	int temp;

	printf("Digite uma string:\n");
	fgets(str, 49, stdin);
	printf("String em minusculo:\n");

	for(int i=0; i<50; i++){
		if(str[i]>=65 && str[i]<=90)
			str[i]= str[i]+32;
	}
	printf("%s",str);
}
