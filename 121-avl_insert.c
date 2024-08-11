#include "binary_trees.h"

/**
 * avl_insert - Inserts a value into an AVL tree and rebalances it
 * @tree: Double pointer to the root node of the AVL tree
 * @value: The value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *node;

    if (tree == NULL)
        return (NULL);

    /* Insert the node like in a BST */
    node = bst_insert(tree, value);
    if (node == NULL)
        return (NULL);

    /* Rebalance the tree */
    return (rebalance_tree(tree));
}

/**
 * rebalance_tree - Rebalances the AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 *
 * Return: The new root node of the tree
 */
avl_t *rebalance_tree(avl_t **tree)
{
    int balance;
    
    if (tree == NULL || *tree == NULL)
        return (NULL);

    balance = binary_tree_balance(*tree);

    /* Left heavy subtree */
    if (balance > 1)
    {
        if (binary_tree_balance((*tree)->left) < 0)
            *tree = rotate_left((*tree)->left);
        return (rotate_right(*tree));
    }

    /* Right heavy subtree */
    if (balance < -1)
    {
        if (binary_tree_balance((*tree)->right) > 0)
            *tree = rotate_right((*tree)->right);
        return (rotate_left(*tree));
    }

    return (*tree);
}
