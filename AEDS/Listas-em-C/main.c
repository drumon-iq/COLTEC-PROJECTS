#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main()
{
	int qntd_Reb, passos;
	Lista2 *cirandinha = lst_cria();
	
	printf("Digite a quantidade de pessoas na roda:\n");
	scanf("%d", &qntd_Reb);

	printf("Digite a quantidade de passos(pulos):\n");
	scanf("%d", &passos);

	for(int i=qntd_Reb; i >= 1; i--) {
		cirandinha = lst2_insere(cirandinha, i);
	}
	
	cirandinha = lcirc2_transforma(cirandinha);
		
	while( cirandinha->prox != cirandinha) {
		int v;

		for(v=0; v < passos; v++){
			cirandinha = cirandinha->prox;
		}

		cirandinha = lst2_retira(cirandinha, cirandinha->info);
	}

	printf("Joseph Jonestar deve ficar na posição %d depois do primeiro da roda", cirandinha->info);

	return 0;
}
