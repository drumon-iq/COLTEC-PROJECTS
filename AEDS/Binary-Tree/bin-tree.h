struct TreeNode{
	int data;
	struct TreeNode* leftNode;
	struct TreeNode* rightNode;
};
typedef struct TreeNode binT_node;

struct dinamic_vector {
	int *vec;
	int size;
};

typedef struct dinamic_vector Array;

void array_insert(Array* array, int data);

binT_node* createNode(int data);		    //Create a binT_node(Can be used for initialization)

int binT_isEmpty(binT_node* root);		    //Test if the tree is empty
void binT_free(binT_node* root); 		    //Free the entire binary tree

binT_node* binT_inOrderIns(binT_node* root, int data); //Insert data in the tree sorted
binT_node* binT_removeNode(binT_node* root, int data); //Remove binT_node containing data in the tree

void binT_printToArray(binT_node* root, Array* vec);

//Retrieve information about the tree
void nodeCount(binT_node* root, int amountOf[]);
void binT_histogram(binT_node* root); //find out how many times a certain information can be found in a binary tree
int binT_treeHeight(binT_node* root); //Didn't code in bin-tree.c and wont fix

int binT_SearchData(binT_node* root, int data);   //Try to find data in tree, 1 - success, 0 - failure (Actually needs to return the node, moron)

//Print the binary tree
void binT_printInOrder(binT_node* root);
void binT_DrawTree(binT_node* root);
