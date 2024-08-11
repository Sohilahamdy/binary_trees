#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common
 *         ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return (NULL);

    /* If first or second is the same as root, then root is the LCA */
    if (first == second)
        return ((binary_tree_t *)first);

    /* If first is root of second or vice versa */
    if (first->parent == second)
        return ((binary_tree_t *)second);
    if (second->parent == first)
        return ((binary_tree_t *)first);

    /* Traverse upwards from first */
    const binary_tree_t *ancestor = first;

    while (ancestor)
    {
        const binary_tree_t *second_ancestor = second;

        while (second_ancestor)
        {
            if (ancestor == second_ancestor)
                return ((binary_tree_t *)ancestor);
            second_ancestor = second_ancestor->parent;
        }
        ancestor = ancestor->parent;
    }

    return (NULL);
}
