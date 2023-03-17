#include <stdio.h>

int main(){
	int inp, count=0;

	printf("Digite um numero: \n");
	scanf("%d",&inp);

	for(int i=1; i<=inp; i++){
		count+=(inp%i==0);
	}
	
	if(count==2){
		printf("O numero %d e primo\n.", inp);
	}else{
		printf("O numero %d nao e primo.\n",inp);
	}
}
