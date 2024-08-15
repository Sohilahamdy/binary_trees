#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_size - Counts the number of nodes in a heap
 * @heap: Pointer to the root node of the heap
 *
 * This function calculates the total number of nodes in the binary heap.
 * It traverses the entire tree to count each node.
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
 * create_node - Creates a new node with the given value
 * @value: Value to insert into the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *create_node(int value)
{
	binary_tree_t *node = binary_tree_node(NULL, value);

	return ((heap_t *)node);
}

/**
 * find_parent - Finds the parent of the node to be inserted
 * @tree: Pointer to the root node of the heap
 * @index: Index of the node to be inserted
 *
 * Return: Pointer to the parent node, or NULL if not found
 */
heap_t *find_parent(heap_t *tree, size_t index)
{
	heap_t *current = tree;
	heap_t *parent = NULL;

	while (index > 0)
	{
		parent = current;
		if (index % 2 == 0)
			current = current->right;
		else
			current = current->left;
		index = (index - 1) / 2;
	}

	return (parent);
}

/**
 * heap_insert_node - Inserts a node into the
 * heap at the first available position
 * @tree: Double pointer to the root node of the heap
 * @value: Value to insert into the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *heap_insert_node(heap_t **tree, int value)
{
	size_t index, size;
	heap_t *new_node = NULL;
	heap_t *parent = NULL;

	if (!tree)
		return (NULL);

	size = heap_size(*tree);
	index = size;

	/* Create new node */
	new_node = create_node(value);
	if (!new_node)
		return (NULL);

	if (!*tree)
	{
		*tree = new_node;
		return (new_node);
	}

	parent = find_parent(*tree, index);

	/* Attach new node to its parent */
	if (index % 2 == 0)
		parent->right = new_node;
	else
		parent->left = new_node;

	new_node->parent = parent;

	return (new_node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert into the heap
 *
 * This function inserts a new value into the Max Binary Heap and
 * rebalances the heap to maintain the Max Heap property.
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;

	if (!root)
		return (NULL);

	new_node = heap_insert_node(root, value);
	if (!new_node)
		return (NULL);

	/* Rebalance the heap */
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		/* Swap values with parent */
		int temp = new_node->n;

		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;

		/* Move up to parent */
		new_node = new_node->parent;
	}

	return (new_node);
}
