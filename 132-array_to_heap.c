#include "binary_trees.h"
#include <stdlib.h>

/**
 * array_to_heap - Builds a Max Binary Heap from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *heap = NULL;
	heap_t *new_node;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		new_node = heap_insert(&heap, array[i]);
		if (!new_node)
		{
			/* Clean up and return NULL on failure */
			heap_delete(heap);
			return (NULL);
		}
	}

	return (heap);
}
