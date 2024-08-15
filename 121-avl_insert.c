#include "binary_trees.h"

/**
 * avl_node_create - Creates a new AVL tree node
 * @value: The value to insert into the node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
avl_t *avl_node_create(int value)
{
    avl_t *node = malloc(sizeof(avl_t));

    if (!node)
        return (NULL);

    node->n = value;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root of the AVL tree
 * @value: The value to insert
 * 
 * Return: Pointer to the newly created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (*tree == NULL)
		return (*tree = avl_node_create(value));

	*tree = avl_insert_node(*tree, value);

	return (*tree);
}

/**
 * avl_insert_node - Helper function to insert a node into AVL tree
 * @tree: Pointer to the root of the AVL tree
 * @value: The value to insert
 * 
 * Return: Pointer to the new root of the subtree
 */
avl_t *avl_insert_node(avl_t *tree, int value)
{
	if (tree == NULL)
		return (avl_node_create(value));

	if (value < tree->n)
		tree->left = avl_insert_node(tree->left, value);
	else if (value > tree->n)
		tree->right = avl_insert_node(tree->right, value);
	else
		return (tree);

	tree = avl_rebalance(tree);

	return (tree);
}

/**
 * rebalance - Rebalances the AVL tree
 * @tree: Pointer to the root of the AVL tree
 * 
 * Return: New root of the AVL tree
 */
avl_t *avl_rebalance(avl_t *tree)
{
	int balance = avl_tree_balance(tree);

	if (balance > 1)
	{
		if (avl_tree_balance(tree->left) < 0)
			tree->left = avl_rotate_left(tree->left);
		tree = avl_rotate_right(tree);
	}
	else if (balance < -1)
	{
		if (avl_balance(tree->right) > 0)
			tree->right = avl_rotate_right(tree->right);
		tree = avl_rotate_left(tree);
	}

	return (tree);
}

/**
 * avl_tree_balance - Computes the balance factor of the AVL tree
 * @tree: Pointer to the root of the AVL tree
 *
 * Return: Balance factor of the tree
 */
int avl_tree_balance(const avl_t *tree)
{
    if (!tree)
        return (0);

    return (avl_balance(tree->left) - avl_balance(tree->right));
}

/**
 * avl_rotate_left - Performs a left rotation on the AVL tree
 * @tree: Pointer to the root of the AVL tree
 *
 * Return: New root of the AVL tree
 */
avl_t *avl_rotate_left(avl_t *tree)
{
    avl_t *new_root = tree->right;
    avl_t *temp = new_root->left;

    new_root->left = tree;
    tree->right = temp;

    return (new_root);
}

/**
 * avl_rotate_right - Performs a right rotation on the AVL tree
 * @tree: Pointer to the root of the AVL tree
 *
 * Return: New root of the AVL tree
 */
avl_t *avl_rotate_right(avl_t *tree)
{
    avl_t *new_root = tree->left;
    avl_t *temp = new_root->right;

    new_root->right = tree;
    tree->left = temp;

    return (new_root);
}

/**
 * max_value - Finds the maximum value among three integers
 * @a: First integer
 * @b: Second integer
 * @c: Third integer
 *
 * Return: The maximum value
 */
int max_value(int a, int b, int c)
{
    int max = a;

    if (b > max)
        max = b;
    if (c > max)
        max = c;

    return max;
}

/**
 * avl_balance - Computes the height of the subtree
 * @tree: Pointer to the root of the AVL tree
 *
 * Return: Height of the subtree
 */
int avl_balance(const avl_t *tree)
{
    if (!tree)
        return (0);

    return (max_value(1 + avl_balance(tree->left),
			    1 + avl_balance(tree->right), 0));
}
