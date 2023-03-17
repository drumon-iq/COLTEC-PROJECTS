#include <stdio.h>

int main(void){

	char str[50], resStr[50];
	int spaceNum=0;

	printf("Digite a string:\n");
	fgets( str, 49, stdin);

	//O loop FOR é relativo ao resStr
	for(int i=0; i+spaceNum<50; i++){
		if(str[i+spaceNum]==32){
			spaceNum++;
			i--;
			continue;
		}
		resStr[i]=str[i+spaceNum];
	}

	printf("String sem os espaços: %s", resStr);
}
