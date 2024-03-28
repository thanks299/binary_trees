#include "binary_trees.h"

/**
 * build_avl_recursive - Recursively builds an AVL tree node.
 *
 * @node: Pointer to the current node.
 * @array: Input array of integers.
 * @size: Size of the array.
 * @mode: 1 to add on the left, 2 to add on the right.
 * Return: No return.
 */
void build_avl_recursive(avl_t **node, int *array, size_t size, int mode)
{
	size_t mid;

	if (size == 0)
		return;

	mid = (size / 2);
	mid = (size % 2 == 0) ? mid - 1 : mid;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[mid]);
		build_avl_recursive(&((*node)->left), array, mid, 1);
		build_avl_recursive(&((*node)->left), array + mid + 1, (size - 1 - mid), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[mid]);
		build_avl_recursive(&((*node)->right), array, mid, 1);
		build_avl_recursive(&((*node)->right), array + mid + 1, (size - 1 - mid), 2);
	}
}

/**
 * sorted_array_to_avl - Creates root node and calls build_avl_recursive.
 *
 * @input_array: Input array of integers.
 * @array_size: Size of the array.
 * Return: Pointer to the root.
 */
avl_t *sorted_array_to_avl(int *input_array, size_t array_size)
{
	avl_t *current_node;
	size_t mid;

	current_node = NULL;

	if (array_size == 0)
		return (NULL);

	mid = (array_size / 2);
	mid = (array_size % 2 == 0) ? mid - 1 : mid;

	current_node = binary_tree_node(current_node, input_array[mid]);

	build_avl_recursive(&current_node, input_array, mid, 1);
	build_avl_recursive(&current_node,
			input_array + mid + 1, (array_size - 1 - mid), 2);

	return (current_node);
}
