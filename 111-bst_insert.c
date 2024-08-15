#include "binary_trees.h"

/**
 * bst_insert_left - Inserts a value in the left child of a node in a BST
 * @current: Pointer to the node where the value should be inserted
 * @value: The value to insert in the tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert_left(bst_t *current, int value)
{
	bst_t *new_node = (bst_t *)binary_tree_node((binary_tree_t *)current, value);

	current->left = new_node;
	return (new_node);
}

/**
 * bst_insert_right - Inserts a value in the right child of a node in a BST
 * @current: Pointer to the node where the value should be inserted
 * @value: The value to insert in the tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert_right(bst_t *current, int value)
{
	bst_t *new_node = (bst_t *)binary_tree_node((binary_tree_t *)current, value);

	current->right = new_node;
	return (new_node);
}

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to insert in the tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);
	
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	
	if (value < (*tree)->n)
	{
		if ((*tree)->left != NULL)
			return (bst_insert(&((*tree)->left), value));
		else
			return ((*tree)->left = binary_tree_node(*tree, value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right != NULL)
			return (bst_insert(&((*tree)->right), value));
		else
			return ((*tree)->right = binary_tree_node(*tree, value));
	}

	return (NULL);
}
