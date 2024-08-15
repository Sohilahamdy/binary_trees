#include "binary_trees.h"

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root of the AVL tree
 * @value: The value to insert
 * 
 * Return: Pointer to the newly created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (*tree == NULL)
		return (*tree = avl_node_create(value));

	*tree = avl_insert_node(*tree, value);

	return (*tree);
}

/**
 * avl_insert_node - Helper function to insert a node into AVL tree
 * @tree: Pointer to the root of the AVL tree
 * @value: The value to insert
 * 
 * Return: Pointer to the new root of the subtree
 */
static avl_t *avl_insert_node(avl_t *tree, int value)
{
	if (tree == NULL)
		return (avl_node_create(value));

	if (value < tree->n)
		tree->left = avl_insert_node(tree->left, value);
	else if (value > tree->n)
		tree->right = avl_insert_node(tree->right, value);
	else
		return (tree);

	tree = avl_rebalance(tree);

	return (tree);
}

/**
 * rebalance - Rebalances the AVL tree
 * @tree: Pointer to the root of the AVL tree
 * 
 * Return: New root of the AVL tree
 */
static avl_t *avl_rebalance(avl_t *tree)
{
	int balance = avl_tree_balance(tree);

	if (balance > 1)
	{
		if (avl_tree_balance(tree->left) < 0)
			tree->left = avl_rotate_left(tree->left);
		tree = avl_rotate_right(tree);
	}
	else if (balance < -1)
	{
		if (avl_balance(tree->right) > 0)
			tree->right = avl_rotate_right(tree->right);
		tree = avl_rotate_left(tree);
	}

	return (tree);
}
