#include "binary_trees.h"
#include <stdlib.h>

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
	size_t i;
	size_t heap_size_value;

	if (!heap || !size)
		return (NULL);

	heap_size_value = heap_size(heap);
	*size = heap_size_value;

    /* Allocate memory for the sorted array */
	array = malloc(sizeof(int) * heap_size_value);
	if (!array)
		return (NULL);

    /* Extract the root node repeatedly and store values in the array */
	for (i = 0; i < heap_size_value; i++)
	{
		array[i] = heap_extract(&heap);
	}

	return (array);
}
