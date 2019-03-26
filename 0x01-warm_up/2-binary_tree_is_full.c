#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to root node
 *
 * Return: 1 if full, 0 if not full or null tree
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->left && tree->right) && !(!tree->left && !tree->right))
		return (0);
	if (tree->left)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	else
		return (1);
}
