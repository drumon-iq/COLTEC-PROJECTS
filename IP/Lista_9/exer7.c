#include <stdio.h>

int numMesesIsentos(float *vet);

void main(void)
{
	float vet[12];

	printf("Digite os valores base para o cálculo de IRRF: \n");
	for(int i=0; i<12; i++)
		scanf(" %f", &vet[i]);
	printf("A isenção de IRRF ocorreu em %d meses desse ano\n", numMesesIsentos(vet));
}

int numMesesIsentos(float *vet)
{
	int retorno=0;

	for(int i=0; i<12; i++)
		if(vet[i] > 1903.98)
			retorno++;
	return retorno;
}
