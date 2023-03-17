#include <stdio.h>

double negativo(double);

void main()
{
	double inp;

	printf("Digite um numero: \n");
	scanf("%lf", &inp);
	printf("Valor negativo: %.2lf\n", negativo(inp));
}

double negativo(double i)
{

	if(i >= 0)
		return i*(-1);
	return i;
}
