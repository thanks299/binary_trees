#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * is_max_heap_recursive - Checks if each node in
 * the binary tree is less than its children.
 * @node: Pointer to the current node.
 * Return: 1 if the max-heap property is satisfied, 0 otherwise.
 **/
int is_max_heap_recursive(const binary_tree_t *node)
{
	int left_check = 1, right_check = 1;

	if (!node)
		return (0);

	if (!node->left && !node->right)
		return (1);

	if (node->left)
	{
		if (node->n <= node->left->n)
			return (0);
		left_check = is_max_heap_recursive(node->left);
	}

	if (node->right)
	{
		if (node->n <= node->right->n)
			return (0);
		right_check = is_max_heap_recursive(node->right);
	}

	return (left_check && right_check);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap.
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if it's a max heap, 0 otherwise.
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_complete;

	if (!tree)
		return (0);

	is_complete = binary_tree_is_complete(tree);

	if (!is_complete)
		return (0);

	return (is_max_heap_recursive(tree));
}

