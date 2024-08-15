#include "binary_trees.h"
#include <limits.h>

/**
 * array_to_avl - Builds an AVL tree from an array of integers
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (array[i] != INT_MIN)
			avl_insert(&tree, array[i]);
	}

	return (tree);
}
