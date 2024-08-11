#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle of
 *
 * Return: Pointer to the uncle node, or NULL if node is NULL,
 *         node has no parent, or node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return (NULL);

    binary_tree_t *parent = node->parent;
    binary_tree_t *grandparent = parent->parent;

    if (grandparent == NULL)
        return (NULL);

    if (parent == grandparent->left)
        return (grandparent->right);
    else
        return (grandparent->left);
}
