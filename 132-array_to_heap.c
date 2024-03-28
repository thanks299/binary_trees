#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root node of the created Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t index;
	heap_t *heap_root = NULL;

	for (index = 0; index < size; index++)
		heap_insert(&heap_root, array[index]);

	return (heap_root);
}

