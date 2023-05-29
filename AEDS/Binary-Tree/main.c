#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bin-tree.h"

#define SUCCESS 0

int main()
{
	binT_node* mytree = binT_inOrderIns(NULL, 6);
	binT_inOrderIns(mytree, 4);
	binT_inOrderIns(mytree, 8);
	binT_inOrderIns(mytree, 3);
	binT_inOrderIns(mytree, 5);
	binT_inOrderIns(mytree, 9);
	binT_inOrderIns(mytree, 7);


	printf("\n");
	binT_DrawTree(mytree);

	printf("\n");
	binT_printInOrder(mytree);
	printf("\n");

	printf("\nInfo sobre os nos:\n");

	int randomVec[] = {0, 0, 0};
	nodeCount(mytree, randomVec);

	printf("Quantidade de nos com 0 filhos(folha): %d\n", randomVec[0]);
	printf("Quantidade de nos com 1 filhos: %d\n", randomVec[1]);
	printf("Quantidade de nos com 2 filhos: %d\n", randomVec[2]);


	printf("\n\n");

	binT_histogram(mytree);

	return SUCCESS;
}
