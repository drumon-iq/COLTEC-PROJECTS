#include <stdio.h>

int linhas, colunas;

void transposta(int matrix[][colunas]);

void main(void)
{
	printf("Digite as dimensões da matriz:\n");

	scanf(" %d%d", &linhas, &colunas);
	int matrix[linhas][colunas];

	printf("Digite a matriz %dx%d\n", linhas, colunas);
	
	for(int a=0; a<linhas; a++){
		for(int b=0; b<colunas; b++){
			scanf(" %d", &matrix[a][b]);
		}
	}

	printf("Matriz transposta: \n");
	transposta(matrix);
}

void transposta(int matrix[linhas][colunas])
{
	for(int a=0; a<colunas; a++){
		for(int b=0; b<linhas; b++){
			printf("%d ", matrix[b][a]);
		}
		printf("\n");
	}
}
