#include <stdio.h>

int main(){
	float MinecraftSteve,tot;

	printf("Digite o valor unitario do xerox:\n");
	scanf("%f",&MinecraftSteve);

	for(int i=1; i<=200; i++){
		tot = MinecraftSteve*i;
		printf("%d = %.2f\n", i, tot);
	}
}
