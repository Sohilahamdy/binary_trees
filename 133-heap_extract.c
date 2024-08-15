#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swap the values of two nodes
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
static void swap_values(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
 * heapify - Restore the Max Heap property
 * @root: Pointer to the root node of the heap
 */
static void heapify(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		swap_values(root, largest);
		heapify(largest);
	}
}

/**
 * find_last_node - Find the last node in level-order traversal
 * @root: Pointer to the root node of the heap
 * @last_node: Double pointer to store the last node
 * @index: Current index
 * @size: Total number of nodes
 */
static void find_last_node(heap_t *root, heap_t **last_node,
		size_t index, size_t *size)
{
	if (!root)
		return;

	if (index == *size - 1)
		*last_node = root;

	find_last_node(root->left, last_node, 2 * index + 1, size);
	find_last_node(root->right, last_node, 2 * index + 2, size);
}

/**
 * heap_extract - Extract the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node = NULL;
	size_t size = 0;
	int root_value;

	if (!root || !*root)
		return (0);

    /* Count the number of nodes in the heap */
	size = heap_size(*root);

    /* Find the last node in the heap */
	find_last_node(*root, &last_node, 0, &size);

	if (size == 0)
		return (0);

    /* Extract the root value */
	root_value = (*root)->n;
	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (root_value);
	}

    /* Replace the root with the last node */
	(*root)->n = last_node->n;
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	free(last_node);

    /* Restore the Max Heap property */
	heapify(*root);

	return (root_value);
}
