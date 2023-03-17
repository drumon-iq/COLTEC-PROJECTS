#include <stdio.h>

int main(){
	
	float inp = 0;
	
	unsigned int a, b, c, d;
	
	while(inp >= 0){
		
		printf("Digite um valor:\n");
		scanf("%f",&inp);
		
		if(inp>=1  && inp<=25){
			a++;
		}
		else if(inp>=26  && inp<=50){
			b++;
		}
		else if(inp>=51  && inp<=75){
			c++;
		}
		else if(inp>=76  && inp<=100){
			d++;
		}
	}
	
	printf("Quantidade de números no intervalo [1-25]: %d\n",a);
	printf("Quantidade de números no intervalo [26-50]: %d\n",b);
	printf("Quantidade de números no intervalo [51-75]: %d\n",c);
	printf("Quantidade de números no intervalo [76-100]: %d\n",d);
	
}
