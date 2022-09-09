#include <stdio.h>

void triang_nums(int);

void main(void)
{
	int inp;

	printf("Digite o numero de linhas do triangulo: \n");
	scanf("%d", &inp);
	printf("Triangulo de números ate %d\n", inp);
	triang_nums(inp);
}


void triang_nums(int i)
{
	for(int a=1; a<=i; a++){
		for(int b=1; b<=a; b++)
			printf("%d", a);
		printf("\n");
	}
}
