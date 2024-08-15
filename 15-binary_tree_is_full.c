#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

    /* If the node is a leaf (no children), it is a full subtree */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

    /* If both children are present, check recursively for both subtrees */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

    /* If one child is missing, the tree is not full */
	return (0);
}
