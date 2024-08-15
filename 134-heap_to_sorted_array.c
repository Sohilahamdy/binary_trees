#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_size - Calculate the number of nodes in a heap
 * @heap: Pointer to the root node of the heap
 *
 * Return: Number of nodes in the heap
 */
size_t heap_size(const heap_t *heap)
{
	if (!heap)
		return (0);
	return (1 + heap_size(heap->left) + heap_size(heap->right));
}

/**
 * heap_to_sorted_array - Convert a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i = 0;
	int extracted_value;

	if (!heap || !size)
		return (NULL);

	*size = heap_size(heap);

    /* Allocate memory for the sorted array */
	array = malloc(*size * sizeof(int));
	if (!array)
		return (NULL);

    /* Extract the root node repeatedly and store values in the array */
	while (*size)
	{
		extracted_value = heap_extract(&heap);
		if (extracted_value == 0 && heap)
		{
			free(array);
			return (NULL);
		}
		array[i++] = extracted_value;
		(*size)--;
	}

	return (array);
}
