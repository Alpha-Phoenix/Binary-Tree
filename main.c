#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(void) {
    BinaryTree *tree = BinaryTree_Create();
    Cell a = {1, 50};
    Cell b = {0, 0};
    Cell c = {2, 100};
    BinaryTree_Insert(tree, a);
    BinaryTree_Insert(tree, b);
    BinaryTree_Insert(tree, c);
    printf("%d", tree->root->left->cell.value);
    BinaryTree_Destroy(&tree);
    return 0;
}

