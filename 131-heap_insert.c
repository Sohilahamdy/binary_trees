#include "binary_trees.h"
#include <stdlib.h>

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
 * binary_tree_insert - Inserts a node into the binary tree at the first available position
 * @tree: Double pointer to the root node of the tree
 * @value: Value to insert into the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *binary_tree_insert(heap_t **tree, int value)
{
    size_t index, size;
    heap_t *new_node = NULL;
    heap_t *current = NULL;
    heap_t *parent = NULL;

    if (!tree)
        return (NULL);

    size = binary_tree_size(*tree);
    index = size;
    
    /* Create new node */
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*tree)
    {
        *tree = new_node;
        return (new_node);
    }

    current = *tree;

    /* Find the parent of the new node */
    while (index > 0)
    {
        parent = current;
        if (index % 2 == 0)
            current = current->right;
        else
            current = current->left;
        index = (index - 1) / 2;
    }

    /* Attach new node to its parent */
    if (index % 2 == 0)
        parent->right = new_node;
    else
        parent->left = new_node;

    new_node->parent = parent;

    return (new_node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert into the heap
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = NULL;

    if (!root)
        return (NULL);

    new_node = binary_tree_insert(root, value);
    if (!new_node)
        return (NULL);

    /* Rebalance the heap */
    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        /* Swap values with parent */
        int temp = new_node->n;
        new_node->n = new_node->parent->n;
        new_node->parent->n = temp;

        /* Move up to parent */
        new_node = new_node->parent;
    }

    return (new_node);
}
