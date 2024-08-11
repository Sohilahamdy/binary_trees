#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Adds a node to the queue
 * @queue: Double pointer to the queue
 * @node: Node to add to the queue
 * @tail: Pointer to the tail of the queue
 */
void enqueue(binary_tree_t **queue, binary_tree_t *node, int *tail)
{
    queue[*tail] = node;
    (*tail)++;
}

/**
 * dequeue - Removes a node from the queue
 * @queue: Double pointer to the queue
 * @head: Pointer to the head of the queue
 *
 * Return: The dequeued node
 */
binary_tree_t *dequeue(binary_tree_t **queue, int *head)
{
    (*head)++;
    return queue[*head - 1];
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node. The value in the node
 *        must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t *queue[1024]; /* Array-based queue for level-order traversal */
    int head = 0, tail = 0;

    if (!tree || !func)
        return;

    enqueue(queue, (binary_tree_t *)tree, &tail); /* Start with the root */

    while (head < tail)
    {
        binary_tree_t *current = dequeue(queue, &head);
        func(current->n); /* Call the function for the current node */

        if (current->left)
            enqueue(queue, current->left, &tail);

        if (current->right)
            enqueue(queue, current->right, &tail);
    }
}
