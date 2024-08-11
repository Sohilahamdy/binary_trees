#include "binary_trees.h"

/**
 * is_bst_helper - Recursively checks if a binary tree is a BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Pointer to the minimum value allowed.
 * @max: Pointer to the maximum value allowed.
 *
 * Return: 1 if tree is a valid BST, otherwise 0.
 */
int is_bst_helper(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max)
{
    if (!tree)
        return (1);

    if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
        return (0);

    return (is_bst_helper(tree->left, min, tree) &&
            is_bst_helper(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (is_bst_helper(tree, NULL, NULL));
}
