#include "binary_trees.h"

/**
 * min_value_node - Find the node with the smallest value greater than the given node
 * @node: Pointer to the node to start searching from
 *
 * Return: Pointer to the node with the minimum value
 */
static avl_t *min_value_node(avl_t *node)
{
    avl_t *current = node;

    while (current && current->left)
        current = current->left;

    return (current);
}

/**
 * remove_node - Remove a node from an AVL tree and rebalance the tree
 * @root: Pointer to the root node of the AVL tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removal and rebalancing
 */
static avl_t *remove_node(avl_t *root, int value)
{
    avl_t *temp;
    int balance;

    if (!root)
        return (NULL);

    if (value < root->n)
        root->left = remove_node(root->left, value);
    else if (value > root->n)
        root->right = remove_node(root->right, value);
    else
    {
        if (!root->left)
        {
            temp = root->right;
            free(root);
            return (temp);
        }
        else if (!root->right)
        {
            temp = root->left;
            free(root);
            return (temp);
        }

        temp = min_value_node(root->right);
        root->n = temp->n;
        root->right = remove_node(root->right, temp->n);
    }

    if (!root)
        return (NULL);

    balance = binary_tree_balance(root);

    if (balance > 1 && binary_tree_balance(root->left) >= 0)
        return (binary_tree_rotate_right(root));

    if (balance > 1 && binary_tree_balance(root->left) < 0)
    {
        root->left = binary_tree_rotate_left(root->left);
        return (binary_tree_rotate_right(root));
    }

    if (balance < -1 && binary_tree_balance(root->right) <= 0)
        return (binary_tree_rotate_left(root));

    if (balance < -1 && binary_tree_balance(root->right) > 0)
    {
        root->right = binary_tree_rotate_right(root->right);
        return (binary_tree_rotate_left(root));
    }

    return (root);
}

/**
 * avl_remove - Remove a value from an AVL tree
 * @root: Pointer to the root node of the AVL tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removal and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (!root)
        return (NULL);

    return (remove_node(root, value));
}
