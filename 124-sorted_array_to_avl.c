#include "binary_trees.h"

/**
 * sorted_array_to_avl - Build an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (sorted_array_to_avl_rec(array, 0, size - 1));
}

/**
 * sorted_array_to_avl_rec - Helper function to build AVL tree from
 * sorted array
 * @array: Pointer to the first element of the array
 * @start: Starting index of the current segment
 * @end: Ending index of the current segment
 *
 * Return: Pointer to the root node of the subtree, or NULL on failure
 */
static avl_t *sorted_array_to_avl_rec(int *array, size_t start, size_t end)
{
	avl_t *node;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(NULL, array[mid]);
	if (!node)
		return (NULL);

	node->left = sorted_array_to_avl_rec(array, start, mid - 1);
	if (node->left)
		node->left->parent = node;

	node->right = sorted_array_to_avl_rec(array, mid + 1, end);

	if (node->right)
		node->right->parent = node;

	return (node);
}
