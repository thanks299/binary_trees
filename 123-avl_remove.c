#include "binary_trees.h"

/**
 * bal - Measures balance factor of an AVL tree
 * @t: Tree to go through
 * Return: Balanced factor
 */
void bal(avl_t **t)
{
	int bf;

	if (t == NULL || *t == NULL)
		return;
	if ((*t)->left == NULL && (*t)->right == NULL)
		return;
	bal(&(*t)->left);
	bal(&(*t)->right);
	bf = binary_tree_balance((const binary_tree_t *)*t);
	if (bf > 1)
		*t = binary_tree_rotate_right((binary_tree_t *)*t);
	else if (bf < -1)
		*t = binary_tree_rotate_left((binary_tree_t *)*t);
}

/**
 * successor - Get the next successor, i.e., the min node in the right subtree
 * @n: Tree node to check
 * Return: The min value of this tree
 */
int successor(bst_t *n)
{
	int l = 0;

	if (n == NULL)
	{
		return (0);
	}
	else
	{
		l = successor(n->left);
		if (l == 0)
		{
			return (n->n);
		}
		return (l);
	}
}

/**
 * remove_type - Function that removes a node depending on its children
 * @r: Node to remove
 * Return: 0 if it has no children, or other value if it has
 */
int remove_type(bst_t *r)
{
	int nv = 0;

	if (!r->left && !r->right)
	{
		if (r->parent->right == r)
			r->parent->right = NULL;
		else
			r->parent->left = NULL;
		free(r);
		return (0);
	}
	else if ((!r->left && r->right) || (!r->right && r->left))
	{
		if (!r->left)
		{
			if (r->parent->right == r)
				r->parent->right = r->right;
			else
				r->parent->left = r->right;
			r->right->parent = r->parent;
		}

		if (!r->right)
		{
			if (r->parent->right == r)
				r->parent->right = r->left;
			else
				r->parent->left = r->left;
			r->left->parent = r->parent;
		}

		free(r);
		return (0);
	}
	else
	{
		nv = successor(r->right);
		r->n = nv;
		return (nv);
	}
}

/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from an AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}

