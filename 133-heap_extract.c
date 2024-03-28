#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_h - measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: Height or 0 if tree is NULL
 */
size_t tree_h(const heap_t *tree)
{
	size_t hl = 0, hr = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hl = 1 + tree_h(tree->left);

	if (tree->right)
		hr = 1 + tree_h(tree->right);

	return ((hl > hr) ? hl : hr);
}

/**
 * size_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node
 * Return: Height or 0 if tree is NULL
 */
size_t size_h(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hl = 1 + size_h(tree->left);

	if (tree->right)
		hr = 1 + size_h(tree->right);

	return (hl + hr);
}

/**
 * _sequence - traverses a binary tree using pre-order traversal
 * @tree: pointer to the root node
 * @n: will be last note in traverse
 * @h: height of tree
 */
void _sequence(heap_t *tree, heap_t **n, size_t h)
{
	if (!tree)
		return;

	if (!h)
		*n = tree;
	h--;

	_sequence(tree->left, n, h);
	_sequence(tree->right, n, h);
}

/**
 * _stack - heapifies max binary heap
 * @root: pointer to binary heap
 */
void _stack(heap_t *root)
{
	int v;
	heap_t *t1, *t2;

	if (!root)
		return;

	t1 = root;

	while (1)
	{
		if (!t1->left)
			break;
		if (!t1->right)
			t2 = t1->left;
		else
		{
			t2 = (t1->left->n > t1->right->n) ? t1->left : t1->right;
		}
		if (t1->n > t2->n)
			break;
		v = t1->n;
		t1->n = t2->n;
		t2->n = v;
		t1 = t2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int v;
	heap_t *h_r, *n;

	if (!root || !*root)
		return (0);
	h_r = *root;
	v = h_r->n;
	if (!h_r->left && !h_r->right)
	{
		*root = NULL;
		free(h_r);
		return (v);
	}

	_sequence(h_r, &n, tree_h(h_r));

	h_r->n = n->n;
	if (n->parent->right)
		n->parent->right = NULL;
	else
		n->parent->left = NULL;
	free(n);
	_stack(h_r);
	*root = h_r;
	return (v);
}

