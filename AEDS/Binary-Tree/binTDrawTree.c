#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bin-tree.h"

#define MIN_DIST 1
#define MATRIX_STR_SIZE 4
#define L -1
#define R 1

typedef struct MatrixData{
	char*** binT_Matrix;
	int height;
	int width;
}MatrixData;
	
MatrixData MatrixInfo;

int findHeight(binT_node *root);
void allocateMatrix();
void writeBinTtoMatrix(binT_node*, int posY, int posX, int dir, int posXant);
void print3dMatrix();

void drawLine(int x1, int x2, int y, char*);

//debugging info
void printMatrixInfo();

void binT_DrawTree(binT_node* root)
{
	//Create the matrix to be printed
	MatrixInfo.height = findHeight(root);
	MatrixInfo.width = ((1+MIN_DIST)*pow(2, MatrixInfo.height-1))-MIN_DIST;
	allocateMatrix();

	//printMatrixInfo();

	writeBinTtoMatrix(root, 0, (MatrixInfo.width - 1)/2, 0, 0);

	print3dMatrix();
}

void writeBinTtoMatrix(binT_node* root, int posY, int posX, int dir, int posXant)
{
	if(root != NULL)
	{

		//This code is garbage but it will stay like this until I have patience to fix
		if(root->data >= 0 && root->data < 10)
		{
			sprintf(MatrixInfo.binT_Matrix[posY*2][posX], " %d ", root->data);
			if(dir == L)
			{
				strncpy(MatrixInfo.binT_Matrix[posY*2-1][posX], "  /", 3);
				drawLine(posX+1, posXant-1, posY*2-2, "___");
			}
			else if(dir == R)
			{
				strncpy(MatrixInfo.binT_Matrix[posY*2-1][posX], "\\  ", 3);
				drawLine(posXant+1, posX-1, posY*2-2, "___");
			}
		}
		else if(root->data < 100 && root->data > -10) 
		{
			sprintf(MatrixInfo.binT_Matrix[posY*2][posX], " %d", root->data);
			if(dir == L)
			{
				strncpy(MatrixInfo.binT_Matrix[posY*2-1][posX], "  /", 3);
				drawLine(posX+1, posXant-1, posY*2-2, "___");
			}
			else if(dir == R)
			{
				strncpy(MatrixInfo.binT_Matrix[posY*2-1][posX], "\\  ", 3);
				drawLine(posXant+1, posX-1, posY*2-2, "___");
			}
		}
		else if(root->data < 1000 && root->data > -100)
		{
			sprintf(MatrixInfo.binT_Matrix[posY*2][posX], "%d", root->data);
			if(dir == L)
			{
				strncpy(MatrixInfo.binT_Matrix[posY*2][posX], " /", 3);
				drawLine(posX+1, posXant-1, posY*2-2, "___");
			}
			else if(dir == R)
			{
				strncpy(MatrixInfo.binT_Matrix[posY*2-1][posX], "\\ ", 3);
				drawLine(posXant+1, posX-1, posY*2-2, "___");
			}
		}
		else
		{
			printf("The binary tree has a value with too many characters to be passed to the matrix, please increase it's string limit");
			exit(1);
		}

		int shift = pow(2, MatrixInfo.height)/pow(2, posY+2);

		writeBinTtoMatrix(root->leftNode, posY+1, posX + (-1 * shift), L, posX);
		writeBinTtoMatrix(root->rightNode, posY+1, posX + shift, R, posX);
	}
}

void drawLine(int x1, int x2, int y, char* string)
{
	for(int i = x1; i<=x2; i++)
	{
		strncpy(MatrixInfo.binT_Matrix[y][i], string, 3);
	}
}

int findHeight(binT_node *root)
{
	if(root == NULL)
		return 0;

	int left_dist = findHeight(root->leftNode);
	int right_dist = findHeight(root->rightNode);

	return (left_dist >= right_dist)? ++left_dist : ++right_dist;
}

void allocateMatrix()
{
	char empty_string[] = "   ";

	//remember that you allocating a pointer to a pointer to a string(char*)
	//Giving a space between each actual line of the matrix for pretty print
	MatrixInfo.binT_Matrix = (char***) malloc((2*MatrixInfo.height - 1) * sizeof(char**));
	for(int h = 0; h < (2*MatrixInfo.height-1); h++)
	{
		//For each pointer to pointer, we allocate a pointer to string(that is a pointer to chars)
		MatrixInfo.binT_Matrix[h] = (char**) malloc(MatrixInfo.width * sizeof(char*));
		for(int w = 0; w < MatrixInfo.width; w++)
		{
			//Now we are going to allocate each individual string of the matrix
			//Each string is a 3 characters vector
			//We make it all "empty", we are going to draw the space and other chars later
			MatrixInfo.binT_Matrix[h][w] = (char*) malloc(MATRIX_STR_SIZE*sizeof(char));
			strncpy(MatrixInfo.binT_Matrix[h][w], empty_string, MATRIX_STR_SIZE-1);
		}
	}
}

void print3dMatrix()
{
	for(int h = 0; h < (2*MatrixInfo.height - 1); h++)
	{
		for(int w = 0; w < MatrixInfo.width; w++)
		{
			printf("%s", MatrixInfo.binT_Matrix[h][w]);
		}
		//Break line
		printf("\n");
	}
}

//Debugging functions
void printMatrixInfo()
{
	printf("Matrix height: %d\n", MatrixInfo.height);
	printf("Matrix width: %d\n", MatrixInfo.width);
}
