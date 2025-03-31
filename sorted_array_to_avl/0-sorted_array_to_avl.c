#include "binary_trees.h"
#include <stdlib.h>

/**
 * sorted_array_to_avl_helper - Recursively builds an AVL tree from a sorted arr
 * @array: The sorted array.
 * @start: The starting index.
 * @end: The ending index.
 * @parent: The parent node.
 *
 * Return: Pointer to the root node of the subtree.
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end, avl_t *parent)
{
    avl_t *node;
    int mid;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;
    node = malloc(sizeof(avl_t));
    if (!node)
        return (NULL);
    node->n = array[mid];
    node->parent = parent;
    node->left = sorted_array_to_avl_helper(array, start, mid - 1, node);
    node->right = sorted_array_to_avl_helper(array, mid + 1, end, node);

    return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: The sorted array.
 * @size: The number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}
