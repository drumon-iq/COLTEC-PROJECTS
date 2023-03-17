#include <stdio.h>
#include <math.h>

struct ponto {
	int x;
	int y;
};

void main()
{
	struct ponto A, B;

	printf("Digite as coordenadas x e y do ponto A:\n");
	scanf(" %d%d", &A.x, &A.y);
	printf("Digite as coordenadas x e y do ponto B:\n");
	scanf(" %d%d", &B.x, &B.y);

	printf("Distancia entre os pontos: %.2f\n", sqrt(pow((B.y-A.y),2)+pow((B.x-A.x),2)));
}
