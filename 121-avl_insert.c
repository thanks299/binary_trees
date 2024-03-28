#include "binary_trees.h"
avl_t *avl_insert_rec(avl_t **c_node, avl_t *p_node, avl_t
		**n_node_ptr, int v_node);



/**
 * avl_insert_rec - Recursively inserts a value into an AVL tree.
 * @c_node: A double pointer to the current node of the AVL tree.
 * @p_node: The parent node of the current working node.
 * @n_node_ptr: A double pointer to store the new node.
 * @v_node: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_rec(avl_t **c_node, avl_t *p_node, avl_t
		**n_node_ptr, int v_node);


avl_t *avl_insert_rec(avl_t **c_node, avl_t *p_node, avl_t
		**n_node_ptr, int v_node)


{
	int b_factor;

	/* If the current node is NULL, create a new node with the given value */
	if (*c_node == NULL)
		return (*n_node_ptr = binary_tree_node(p_node, v_node));

	/* Recursive insertion based on comparison of values */
	if ((*c_node)->n > v_node)
	{
		(*c_node)->left = avl_insert_rec(&(*c_node)->left,
				*c_node, n_node_ptr, v_node);
		if ((*c_node)->left == NULL)
			return (NULL);
	}
	else if ((*c_node)->n < v_node)
	{
		(*c_node)->right = avl_insert_rec(&(*c_node)->right,
				*c_node, n_node_ptr, v_node);
		if ((*c_node)->right == NULL)
			return (NULL);
	}
	else
		return (*c_node);

	/* Update the balance factor of the current node */
	b_factor = binary_tree_balance(*c_node);

	/* Perform rotations if necessary to maintain AVL balance */
	if (b_factor > 1 && (*c_node)->left->n > v_node)
		*c_node = binary_tree_rotate_right(*c_node);
	else if (b_factor < -1 && (*c_node)->right->n < v_node)
		*c_node = binary_tree_rotate_left(*c_node);
	else if (b_factor > 1 && (*c_node)->left->n < v_node)
	{
		(*c_node)->left = binary_tree_rotate_left((*c_node)->left);
		*c_node = binary_tree_rotate_right(*c_node);
	}
	else if (b_factor < -1 && (*c_node)->right->n > v_node)
	{
		(*c_node)->right = binary_tree_rotate_right((*c_node)->right);
		*c_node = binary_tree_rotate_left(*c_node);
	}

	return (*c_node);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_insert(avl_t **tree, int value)


{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_rec(tree, *tree, &new_node, value);
	return (new_node);
}

