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
    avl_t *new_node;

    if (!tree)
        return (NULL);

    if (*tree == NULL)
    {
        new_node = binary_tree_node(NULL, value);
        if (!new_node)
            return (NULL);
        *tree = new_node;
    }
    else
    {
        *tree = avl_insert_node(*tree, value);
        if (!*tree)
            return (NULL);
        // Rebalance the tree
        *tree = rebalance(*tree);
    }

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
        return (binary_tree_node(NULL, value));

    if (value < tree->n)
        tree->left = avl_insert_node(tree->left, value);
    else if (value > tree->n)
        tree->right = avl_insert_node(tree->right, value);
    else
        return (tree);

    return (rebalance(tree));
}

/**
 * rebalance - Rebalances the AVL tree
 * @tree: Pointer to the root of the AVL tree
 * 
 * Return: New root of the AVL tree
 */
static avl_t *rebalance(avl_t *tree)
{
    int balance = binary_tree_balance(tree);

    if (balance > 1)
    {
        if (binary_tree_balance(tree->left) < 0)
            tree->left = binary_tree_rotate_left(tree->left);
        tree = binary_tree_rotate_right(tree);
    }
    else if (balance < -1)
    {
        if (binary_tree_balance(tree->right) > 0)
            tree->right = inary_tree_rotate_right(tree->right);
        tree = inary_tree_rotate_left(tree);
    }

    return (tree);
}
