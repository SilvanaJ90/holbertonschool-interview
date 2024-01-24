
#ifndef BINARY_H
#define BINARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

heap_t *heap_insert(heap_t **root, int value);
int binary_tree_is_perfect(const binary_tree_t *tree, size_t depth, size_t level);
size_t binary_tree_height(const binary_tree_t *tree);
void heapify_up(heap_t *node);
heap_t *get_insertion_point(heap_t *root);

#endif /* BINARY */