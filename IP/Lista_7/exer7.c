#include <stdio.h>

int main(void){

	char str[50];
	int magicNum;

	printf("Digite uma string:\n");
	fgets(str, 49, stdin);

	for(int i=0; i<50; i++){
		if(str[i]!='\0'){
			continue;
		}
		magicNum=i;
		break;
	}

	printf("String invertida:");
	for(int i=magicNum; i>=0; i--){
		printf("%c",str[i]);
	}

}
