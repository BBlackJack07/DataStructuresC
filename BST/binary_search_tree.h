#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct bst_node {
    int data;
    struct bst_node* left;
    struct bst_node* right;
} bst_node;

bst_node* bst_search(bst_node* root, const int data);
void bst_delete(bst_node** root);
void bst_delete_branch(bst_node** root, const int data);
void bst_insert(bst_node** root, const int data);
void postorder_print(bst_node* root);
void inorder_print(bst_node* root);
void preorder_print(bst_node* root);
void bst_copy(bst_node** copy, bst_node* orig);
int bst_depth(bst_node* root);
int bst_sum_leaves(bst_node* root);
int bst_size(bst_node* root);

#endif
