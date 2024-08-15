#include "binary_trees.h"
#include <stdbool.h>

/**
 * height - Computes the height of a binary tree and checks balance
 * @tree: Pointer to the root node of the tree
 * @balanced: Pointer to a boolean that will be set if the tree is balanced
 *
 * Return: The height of the tree if balanced, -1 otherwise
 */
static int height(const binary_tree_t *tree, bool *balanced)
{
	int left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = height(tree->left, balanced);
	right_height = height(tree->right, balanced);

	if (left_height == -1 || right_height == -1 || abs(left_height - right_height)
			> 1)
	{
		*balanced = false;
		return (-1);
	}

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Checks if a binary tree is a valid binary search tree
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value allowed for the node
 * @max: Maximum value allowed for the node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
static int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
	{
		return (1);
	}

	if (tree->n <= min || tree->n >= max)
	{
		return (0);
	}

	return (is_bst(tree->left, min, tree->n) && is_bst(tree->right, tree->n, max))
		;
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	bool balanced = true;

	if (tree == NULL)
	{
		return (0);
	}

    /* Check if the tree is a BST */
	if (!is_bst(tree, INT_MIN, INT_MAX))
	{
		return (0);
	}

    /* Check if the tree is balanced */
	if (height(tree, &balanced) == -1)
	{
		return (0);
	}

	return (1);
}
