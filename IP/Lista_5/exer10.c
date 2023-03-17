#include <stdio.h>

int main(){
	float ing, lucro;
	int pess=0;

	for(ing=5; ing>=1; ing-=0.5){
		pess = 120+((5-ing)*2)*26;
		lucro = pess*ing - 200;
		printf("preco do ingresso: R$ %.1f / publico esperado: %d / lucro esperado: R$ %.2f\n", ing, pess, lucro);
	}
}
