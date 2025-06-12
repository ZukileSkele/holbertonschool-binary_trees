#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 255

static size_t _height(const binary_tree_t *tree);
static void _print(const binary_tree_t *tree, int offset, int depth, char **s);

void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    size_t height;
    int i;

    if (!tree)
        return;

    height = _height(tree);
    s = malloc(sizeof(*s) * (height + 1));
    if (!s)
        return;

    for (i = 0; i <= (int)height; i++)
    {
        s[i] = malloc(WIDTH);
        if (!s[i])
            return;
        memset(s[i], 32, WIDTH - 1);
        s[i][WIDTH - 1] = '\0';
    }

    _print(tree, 0, 0, s);

    for (i = 0; i <= (int)height; i++)
    {
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}

static size_t _height(const binary_tree_t *tree)
{
    size_t left, right;

    if (!tree)
        return (0);

    left = _height(tree->left);
    right = _height(tree->right);

    return (left > right ? left : right) + 1;
}

static void _print(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char buffer[6];
    int width = 5;

    if (!tree)
        return;

    sprintf(buffer, "(%03d)", tree->n);

    _print(tree->left, offset, depth + 1, s);
    strncpy(s[depth] + offset, buffer, width);
    _print(tree->right, offset + width + 1, depth + 1, s);
}

