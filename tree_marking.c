#include <stdio.h> 
#include <stdlib.h> 

// STRUCTURE OF TREE
typedef struct tree_node_tag 
{ 
	int data;
    int marked; 
	struct tree_node_tag* left; 
	struct tree_node_tag* right; 
}   tree_node; 

// FUNCTION TO MARK THE TREE
void Mark_Tree(tree_node* root) 
{ 
	tree_node *current, *prev; 

	if (root == NULL) 
		return; 

	current = root; 
	while (current != NULL) { 

		if (current->left == NULL) { 
			printf("%d ", current->data);
            current->marked = 1; 
			current = current->right; 
		} 
		else { 

			/* Find the inorder predecessor of current */
			prev = current->left; 
			while (prev->right != NULL && prev->right != current) 
				prev = prev->right; 

			/* Make current as the right child of its inorder 
			predecessor */
			if (prev->right == NULL) { 
				prev->right = current; 
				current = current->left; 
			} 

			/* Revert the changes made in the 'if' part to restore 
			the original tree i.e., fix the right child 
			of predecessor */
			else 
            { 
				prev->right = NULL; 
				printf("%d ", current->data);
                current->marked = 1; 
				current = current->right; 
			} 
		} 
	} 
} 

// CREATION OF NEW NODE
tree_node* makeNode(int data) 
{ 
	tree_node* node;
    node = (tree_node*)malloc(sizeof(tree_node)); 
	node->data = data;
    node->marked = 0; 
	node->left = NULL; 
	node->right = NULL; 

	return (node); 
} 


void main() 
{
    // CREATION OF TREE 
	tree_node* root = makeNode(1); 
	root->left = makeNode(2); 
	root->right = makeNode(3); 
	root->left->left = makeNode(4); 
	root->left->right = makeNode(5);
    root->right->left = makeNode(6);
    root->right->right = makeNode(7); 

    // MARKING OF TREE NODES
	Mark_Tree(root);  
} 
