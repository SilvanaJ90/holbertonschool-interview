#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 * @depth: Current depth of the tree.
 * @level: Level of the tree to check for perfection.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
    if (!tree)
        return (depth == level);

    if (!tree->left || !tree->right)
        return (0);

    return (binary_tree_is_perfect(tree->left, depth, level + 1) &&
            binary_tree_is_perfect(tree->right, depth, level + 1));
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    size_t depth = 0;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    depth = binary_tree_height(*root);

    if (binary_tree_is_perfect(*root, depth, 0))
    {
        parent = get_insertion_point(*root);
        new_node = binary_tree_node(parent, value);

        if (!new_node)
            return (NULL);

        if (!parent->left)
            parent->left = new_node;
        else
            parent->right = new_node;

        heapify_up(new_node);
        return (new_node);
    }

    return (NULL);
}

/**
 * heapify_up - Restores the Max Heap property after insertion
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;

        node = node->parent;
    }
}

/**
 * get_insertion_point - Gets the insertion point for the new node
 * @root: Pointer to the root node of the Heap
 * Return: Pointer to the parent node of the new node
 */
heap_t *get_insertion_point(heap_t *root)
{
    heap_t *parent;

    while (root)
    {
        parent = root;
        root = root->left;
    }

    return (parent);
}