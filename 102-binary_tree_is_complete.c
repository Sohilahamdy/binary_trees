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
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    binary_tree_t *queue[1024];
    int head = 0, tail = 0;
    int flag = 0; /* Indicates we've encountered a non-full node */

    if (!tree)
        return (0);

    enqueue(queue, (binary_tree_t *)tree, &tail);

    while (head < tail)
    {
        binary_tree_t *current = dequeue(queue, &head);

        if (current->left)
        {
            if (flag)
                return (0);
            enqueue(queue, current->left, &tail);
        }
        else
        {
            flag = 1;
        }

        if (current->right)
        {
            if (flag)
                return (0);
            enqueue(queue, current->right, &tail);
        }
        else
        {
            flag = 1;
        }
    }

    return (1);
}
