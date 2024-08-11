#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    size_t total_nodes, index;
    
    if (!tree)
        return (0);

    total_nodes = binary_tree_size(tree);
    index = binary_tree_index(tree);

    return (binary_tree_is_complete(tree, index, total_nodes) &&
            binary_tree_is_max_heap(tree));
}

/**
 * binary_tree_size - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_index - Calculates the index of a node in a complete binary tree
 * @tree: Pointer to the node
 *
 * Return: Index of the node
 */
size_t binary_tree_index(const binary_tree_t *tree)
{
    size_t index = 0;

    while (tree->parent)
    {
        if (tree->parent->right == tree)
            index = 2 * index + 1;
        else
            index = 2 * index;

        tree = tree->parent;
    }

    return (index);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @total_nodes: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree, size_t index, size_t total_nodes)
{
    if (!tree)
        return (1);

    if (index >= total_nodes)
        return (0);

    return (binary_tree_is_complete(tree->left, 2 * index + 1, total_nodes) &&
            binary_tree_is_complete(tree->right, 2 * index + 2, total_nodes));
}

/**
 * binary_tree_is_max_heap - Checks if a binary tree is a max heap
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int binary_tree_is_max_heap(const binary_tree_t *tree)
{
    if (!tree)
        return (1);

    if (tree->left && tree->n < tree->left->n)
        return (0);

    if (tree->right && tree->n < tree->right->n)
        return (0);

    return (binary_tree_is_max_heap(tree->left) &&
            binary_tree_is_max_heap(tree->right));
}
