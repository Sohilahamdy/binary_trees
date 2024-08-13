#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to insert in the tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *current = NULL;
    bst_t *new_node = NULL;

    if (tree == NULL)
        return (NULL);

    /* If the tree is empty, the new node becomes the root */
    if (*tree == NULL)
    {
	new_node = (bst_t *)binary_tree_node((binary_tree_t *)current, value);
        *tree = new_node;
        return (new_node);
    }

    current = *tree;

    while (current)
    {
        if (value == current->n)
            return (NULL);  /* Ignore if the value already exists */

        if (value < current->n)
        {
            if (current->left == NULL)
            {
                new_node = (bst_t *)binary_tree_node((binary_tree_t *)current, value);
                current->left = new_node;
                return (new_node);
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                new_node = (bst_t *)binary_tree_node((binary_tree_t *)current, value);
                current->right = new_node;
                return (new_node);
            }
            current = current->right;
        }
    }

    return (NULL);  /* If we exit the loop, insertion failed */
}
