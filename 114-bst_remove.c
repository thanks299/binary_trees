#include "binary_trees.h"

bst_t *sort_node(bst_t *root, int value);


/**
 * sort_node - Finds a node with a specific value in a Binary Search Tree (BST)
 * @root: Pointer to the root node
 * @value: Value to search for in the tree
 *
 * Return: Pointer to node with the specified value, NULL otherwise
 */
bst_t *sort_node(bst_t *root, int value)
{
	if (!root || root->n == value)
		return (root);

	if (value < root->n)
		return (sort_node(root->left, value));
	else
		return (sort_node(root->right, value));
}

/**
 * find_inorder_inheritor - Finds the in-order inheritor of a node in a BST
 * @node: Pointer to the node
 *
 * Return: Pointer to the in-order inheritor
 */
bst_t *find_inorder_inheritor(bst_t *node)
{
	bst_t *inheritor = node->right;

	while (inheritor->left != NULL)
		inheritor = inheritor->left;

	return (inheritor);
}

/**
 * remove_node - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree
 * @node_to_remove: Pointer to the node to be removed
 *
 * Return: Pointer to the new root node
 */
bst_t *remove_node(bst_t *root, bst_t *node_to_remove)
{
	bst_t *new_node;

	/* Different cases when removing a node */
	if (!node_to_remove->left)
	{
		/* Node has no left child or one child */
		if (node_to_remove->right != NULL)
			node_to_remove->right->parent = node_to_remove->parent;

		if (node_to_remove->parent == NULL)
			root = node_to_remove->right;
		else if (node_to_remove == node_to_remove->parent->left)
			node_to_remove->parent->left = node_to_remove->right;
		else
			node_to_remove->parent->right = node_to_remove->right;

		free(node_to_remove);
	}
	else if (!node_to_remove->right)
	{
		/* Node has no right child */
		node_to_remove->left->parent = node_to_remove->parent;

		if (!node_to_remove->parent)
			root = node_to_remove->left;
		else if (node_to_remove == node_to_remove->parent->left)
			node_to_remove->parent->left = node_to_remove->left;
		else
			node_to_remove->parent->right = node_to_remove->left;

		free(node_to_remove);
	}
	else
	{
		/* Find the in-order inheritor */
		new_node = find_inorder_inheritor(node_to_remove);

		/* Replace node with its in-order inheritor */
		if (new_node->right != NULL)
			new_node->right->parent = new_node->parent;

		if (!new_node->parent)
			root = new_node->right;
		else if (new_node == new_node->parent->left)
			new_node->parent->left = new_node->right;
		else
			new_node->parent->right = new_node->right;

		/* Copy value from the in-order inheritor to the original node */
		node_to_remove->n = new_node->n;

		free(new_node);
	}

	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree
 * @value: Value to remove in tree
 *
 * Return: Pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node_to_remove;

	if (!root)
		return (NULL);

	/* Find the node to be removed */
	node_to_remove = sort_node(root, value);

	if (!node_to_remove)
		return (root);

	return (remove_node(root, node_to_remove));
}

