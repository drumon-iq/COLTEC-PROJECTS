#include <stdio.h>

float dobro_do_maior(float, float);

void main(void)
{	float a, b, resultado;
	scanf("%f%f", &a, &b);
	resultado = dobro_do_maior(a,b);
	printf("O dobro do maior valor e %.1f\n", resultado);
}

float  dobro_do_maior(float a, float b)
{
	if(a>b)
		return a*2;
	return b*2;
}
