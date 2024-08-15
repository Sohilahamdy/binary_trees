#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	bst_t *root;
	bst_t *node;

	root = NULL;
	node = bst_insert(&root, 98);
	node = bst_insert(&root, 402);
	node = bst_insert(&root, 12);
	node = bst_insert(&root, 46);
	node = bst_insert(&root, 128);
	node = bst_insert(&root, 256);
	node = bst_insert(&root, 512);
	node = bst_insert(&root, 1);
	node = bst_insert(&root, 128);

	binary_tree_print(root);
	return (0);
}
