#include <stdio.h>

int main(void){

	char str[50];
	printf("Digite a string:\n");
	fgets(str, 49, stdin);

	for(int i=0; i<50; i++){
		if(str[i]>=65 && str[i]<90){
			str[i] = str[i]+1;
		}
		else if(str[i] == 90){
			str[i] = 65;
		}
		else if(str[i]>=97 && str[i]<122){
			str[i] = str[i]+1;
		}
		else if(str[i] == 122){
			str[i] = 97;
		}
	}

	printf("String substituida: %s", str);
}
