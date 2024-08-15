#include "binary_trees.h"

static avl_t *handle_removal(avl_t *root);

/**
 * remove_node - Remove a node from an AVL tree and rebalance the tree
 * @root: Pointer to the root node of the AVL tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree
 */
static avl_t *remove_node(avl_t *root, int value)
{
        if (!root)
                return (NULL);

        if (value < root->n)
                root->left = remove_node(root->left, value);
        else if (value > root->n)
                root->right = remove_node(root->right, value);
        else
                root = handle_removal(root);

        if (!root)
                return (NULL);

        return (balance_avl(root));
}

/**
 * min_value_node - Find the node with the smallest value
 * greater than the given node
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
 * handle_removal - Handle the removal of a node from the AVL tree
 * @root: Pointer to the node to remove
 *
 * Return: Pointer to the new root node after removal
 */
static avl_t *handle_removal(avl_t *root)
{
	avl_t *temp;

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

	return (root);
}

/**
 * balance_avl - Rebalance the AVL tree after node removal
 * @root: Pointer to the root node of the tree
 *
 * Return: Pointer to the balanced root node
 */
static avl_t *balance_avl(avl_t *root)
{
	int balance = binary_tree_balance(root);

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
 * Return: Pointer to the new root node of the tree after removal and
 * rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);

	return (remove_node(root, value));
}
