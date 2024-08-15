#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/**
 * struct heap_s - Max Binary Heap node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 *
 * Description: Node structure for a Max Binary Heap.
 */
typedef struct heap_s
{
	int n;
	struct heap_s *parent;
	struct heap_s *left;
	struct heap_s *right;
} heap_t;

/**
 * struct bst_s - Binary Search Tree node
 *
 * @n: Integer stored in the node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 *
 * Description: Node structure for a Binary Search Tree.
 */
typedef struct bst_s
{
	int n;
	struct bst_s *parent;
	struct bst_s *left;
	struct bst_s *right;
} bst_t;


/**
 * struct avl_s - AVL Tree node
 *
 * @n: Integer stored in the node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @height: Height of the node in the tree
 *
 * Description: Node structure for an AVL Tree,
 * which is a self-balancing binary search tree.
 */
typedef struct avl_s
{
	int n;
	struct avl_s *parent;
	struct avl_s *left;
	struct avl_s *right;
	int height;
} avl_t;

/* Function prototypes */
void binary_tree_print(const binary_tree_t *tree);
void bst_print(const bst_t *tree);
void bst_delete(bst_t *tree);
void heap_print(const heap_t *tree);
void heap_delete(heap_t *heap);
void print_avl_tree(avl_t *tree);
void binary_tree_delete(binary_tree_t *tree);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree, size_t index, size_t total_nodes);
int binary_tree_is_bst(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);
int binary_tree_is_max_heap(const binary_tree_t *tree);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
int avl_balance(const avl_t *tree);
int avl_tree_balance(const avl_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_index(const binary_tree_t *tree);
size_t heap_size(const heap_t *heap);
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *avl_rotate_left(avl_t *tree);
avl_t *avl_rotate_right(avl_t *tree);
avl_t *avl_node_create(int value);
avl_t *avl_insert_node(avl_t *tree, int value);
avl_t *avl_rebalance(avl_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

#endif /* _BINARY_TREES_H_ */
