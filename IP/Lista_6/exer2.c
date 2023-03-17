#include <stdio.h>

int main(){
	int res = 0;
	for(int i=100; i>=0; i--){
		if(i%5 == 0){
			continue;
		}
		res+=i;
	}
	printf("Soma de 1 a 100 excluindo os múltiplos de 5: %d \n", res);
}
