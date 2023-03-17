#include <stdio.h>

int main(){
	int inp, res;
	char op;
	
	scanf("%d",&res);

	do{
		scanf(" %c",&op);
		if(!(op == '=')){
			scanf("%d",&inp);

			switch(op){
				case '+':
					res+=inp;
					printf("Resultado: %d\n", res);
					break;
				case '-':
					res-=inp;
					printf("Resultado: %d\n", res);
					break;
				case '*':
					res*=inp;
					printf("Resultado: %d\n", res);
					break;
				case '/':
					if(res%inp==0){
					res/=inp;
					printf("Resultado: %d\n", res);
					}
					else{
						printf("Operação não pode ser realizada\n");
					}
					break;
			
			}
		}
		else{
			return 0;
		}
	
	}while(1);
}
