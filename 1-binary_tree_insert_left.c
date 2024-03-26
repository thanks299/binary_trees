#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new left-child node in a binary tree
 *
 * @parent: Pointer to the parent node of the left-child node to insert.
 * @value: Value of the new node to be inserted.
 *
 * Return: Pointer to the newly created node or NULL if an error occurs.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *newNode = NULL;
if (parent == NULL)
	return (NULL);

newNode = malloc(sizeof(binary_tree_t));

if (newNode == NULL)
	return (NULL);

newNode->n = value;
newNode->parent = parent;
newNode->left = NULL;
newNode->right = parent->left;

parent->left = newNode;

if (newNode->right != NULL)
	newNode->right->parent = newNode;

    return (newNode);
}
