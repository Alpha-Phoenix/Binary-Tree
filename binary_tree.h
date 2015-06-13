#ifndef BINARY_TREE
#define BINARY_TREE

#include <stdbool.h>
#define null NULL

typedef struct {
    int key;
    int value;
} Cell;

typedef struct Node {
    Cell cell;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *root;
} BinaryTree;

BinaryTree* BinaryTree_Create();
void BinaryTree_Destroy(BinaryTree* tree);
void BinaryTree_Clear(BinaryTree* tree);
void BinaryTree_Insert(BinaryTree *tree, Cell cell);

#endif // BINARY_TREE

