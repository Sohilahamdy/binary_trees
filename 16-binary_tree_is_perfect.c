#include "binary_trees.h"

/**
 * tree_depth - Measures the depth of the deepest leaf node
 * @tree: Pointer to the root node of the tree
 *
 * Return: Depth of the deepest leaf node
 */
static int tree_depth(const binary_tree_t *tree)
{
	int left_depth, right_depth;

	if (tree == NULL)
		return (0);

	left_depth = tree_depth(tree->left);
	right_depth = tree_depth(tree->right);

	if (tree->left && tree->right)
		return (1 + (left_depth > right_depth ? left_depth : right_depth));
	else
		return (1);
}

/**
 * is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 * @depth: Depth of the tree
 * @level: Current level of the node
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
static int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = tree_depth(tree);

	return (is_perfect(tree, depth, 0));
}
