#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bin-tree.h"

//Create a node(Can be used for initialization)
binT_node* createNode(int data)
{
	binT_node *newNode = (binT_node*) malloc(sizeof(binT_node));

	if(newNode == NULL){
		printf("Failed to allocate new binT_node, bailling out!\n");
		exit(EXIT_FAILURE);
	}

	newNode->data = data;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;

	return newNode;
}

//Insert data in the tree sorted
binT_node* binT_inOrderIns(binT_node* root, int data)
{
	//	The code will be structured to use recursion
	//The actual only occasion where the data is inserted is when
	//we find a leaf in the tree, and then we use createNode();
	//for that we do 2 checks and follow the tree through recursion

	if(root == NULL){
		binT_node* newNode = createNode(data);
		return newNode;
	}
	else if(data <= root->data){	//Go left
		root->leftNode = binT_inOrderIns(root->leftNode, data);
	}
	else{			//Go right
		root->rightNode = binT_inOrderIns(root->rightNode, data);
	}

	return root;
}

binT_node* binT_removeNode(binT_node* root, int data)
{
}

void binT_printInOrder(binT_node* root)
{
	// One way of doing this is to recursion this function to oblivion
	// Follow left => print => follow right => eventually die
	// Starts at root, move all the way to left, then slowly goes
	// moving to the right
	
	if(root != NULL){
 		//The idea is that the code will only progress once it finds it's end (the leaf) and the recursion ends there, allowing the function to continue
		binT_printInOrder(root->leftNode);
		printf("%d ", root->data);
		binT_printInOrder(root->rightNode);
	}
}

void nodeCount(binT_node* root, int amountOf[])
{
	//Too late in the night for me to care of writing good code

	if(root != NULL){
		int i = 0;

		nodeCount(root->leftNode, amountOf);

		if(root->leftNode != NULL)
			i++;
		if(root->rightNode != NULL)
			i++;

		switch(i)
		{
			case 0:
				amountOf[0]++;
				break;
			case 1:
				amountOf[1]++;
				break;
			case 2:
				amountOf[2]++;
				break;
		}


		nodeCount(root->rightNode, amountOf);
		return;
	}
}

void binT_histogram(binT_node* root)
{
	Array* array = malloc(sizeof(Array));
	array->size = 0;

 	binT_printToArray(root, array);

	for(int i = 1; i< array->size; i += 2)
		printf("%d aparece %d vez(es)\n", array->vec[i], array->vec[i-1]);
}

void binT_printToArray(binT_node* root, Array *array)
{
	if(root != NULL)
	{
		binT_printToArray(root->leftNode, array);

		if(array->vec != NULL && array->vec[array->size - 1] == root->data)
		{
			array->vec[array->size - 2]++;
		}
		else
		{
			array_insert(array, 1);
			array_insert(array, root->data);
		}

		binT_printToArray(root->rightNode, array);
	}
}

void array_insert(Array* array, int data)
{
	if(array->vec == NULL)
	{
		//initializate the array if it is not initializated
		array->vec = (int*) malloc(sizeof(int));

		array->vec[0] = data;
		array->size++;
		return;
	}

	array->size++;
	array->vec = realloc(array->vec, array->size*sizeof(int));

	if(array->vec == NULL)
	{
		printf("Couldn't realloc pointer, bailling out\n");
		exit(1);
	}

	array->vec[array->size - 1] = data;

	return;
}
