#include "binary_trees.h"

/**
 * min_value_node - Finds the node with the minimum value in a BST
 * @node: Pointer to the node to start the search from
 *
 * Return: Pointer to the node with the minimum value
 */
bst_t *min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the BST
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n) /* Go to the left subtree */
		root->left = bst_remove(root->left, value);
	else if (value > root->n) /* Go to the right subtree */
		root->right = bst_remove(root->right, value);
	else /* Found the node to be deleted */
	{
		if (root->left == NULL) /* Node with one or no child */
		{
			bst_t *temp = root->right;

			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}

		/* Node with two children: Get the in-order successor */
		bst_t *temp = min_value_node(root->right);

		/* Copy the in-order successor's content to this node */
		root->n = temp->n;

		/* Delete the in-order successor */
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
