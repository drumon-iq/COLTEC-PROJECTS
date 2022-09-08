#include <stdio.h>

void tempo(int);

void main(void)
{
	int inp;

	printf("Digite o numero de segundos: \n");
	scanf(" %d", &inp);
	printf("Tempo no formato HH:MM:SS: ");
	tempo(inp);
}

void tempo(int seg)
{
	int horas, min;

	min = seg/60;
	seg-= min*60;

	horas = min/60;
	min-= horas*60;

	printf("%.2d:%.2d:%.2d", horas, min, seg);
}

