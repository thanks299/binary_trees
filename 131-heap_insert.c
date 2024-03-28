#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node.
 *         NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *current, *new_node, *parent;
	int tree_size, leaves, subtree, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	current = *root;
	tree_size = binary_tree_size(current);
	leaves = tree_size;

	for (level = 0, subtree = 1; leaves >= subtree; subtree *= 2, level++)
		leaves -= subtree;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		current = leaves & bit ? current->right : current->left;

	new_node = binary_tree_node(current, value);
	leaves & 1 ? (current->right = new_node) : (current->left = new_node);

	parent = new_node;
	for (; parent->parent && (parent->n > parent->parent->n);
			parent = parent->parent)
	{
		tmp = parent->n;
		parent->n = parent->parent->n;
		parent->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Tree to measure the size of.
 *
 * Return: Size of the tree.
 *         0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

