#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void clearTree(Node* root) {
    if (root == null)
        return;
    clearTree(root->left);
    clearTree(root->right);
    free(root);
}

void insert(Cell cell, Node **root) {
    if ((*root) == null) {
        if (((*root) = (Node*) malloc(sizeof(Node))) == null) {
            fprintf(stderr, "Without memory!");
            exit(EXIT_FAILURE);
        }

        (*root)->left = null;
        (*root)->right = null;
        (*root)->cell = cell;
        return;
    }

    if (cell.key < (*root)->cell.key) {
        insert(cell, &((*root)->left));
    } else if (cell.key > (*root)->cell.key) {
        insert(cell, &((*root)->right));
    }
}

BinaryTree* BinaryTree_Create() {
    BinaryTree *tree;

    if (!(tree = (BinaryTree*) malloc(sizeof (BinaryTree)))) {
        fprintf(stderr, "Without memory!");
        exit(EXIT_FAILURE);
    }

    tree->root = null;
    return tree;
}

void BinaryTree_Destroy(BinaryTree** tree) {
    BinaryTree_Clear(tree);
    free(*tree);
    *tree = null;
}

void BinaryTree_Clear(BinaryTree** tree) {
    clearTree((*tree)->root);
    (*tree)->root = null;
}

void BinaryTree_Insert(BinaryTree *tree, Cell cell) {
    insert(cell, &tree->root);
}
