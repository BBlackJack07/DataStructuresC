#include <stdlib.h>
#include <stdio.h>
#include "binary_search_tree.h"

static bst_node* bst_new_node(int data) {
    bst_node* node = malloc(sizeof(bst_node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

static void bst_del_node(bst_node** node) {
    if ((*node)->left != NULL) {
        bst_del_node(&((*node)->left));
    }

    if ((*node)->right != NULL) {
        bst_del_node(&((*node)->right));
    }
    free(*node);
    *node = NULL;
}

void bst_insert(bst_node** root, int data) { 
    if (*root == NULL) {
        *root = bst_new_node(data);
    }
    else if (data < (*root)->data) {
        bst_insert(&(*root)->left, data);
    }
    else if (data > (*root)->data) {
        bst_insert(&(*root)->right, data);
    }
}

void bst_delete_branch(bst_node** root, const int data) {
    if (*root == NULL) { return; }
    bst_node* toDelete = bst_search(*root, data);
    if (toDelete == NULL) { return; }
    bst_del_node(&toDelete);
}

void bst_delete(bst_node** root) {
    bst_del_node(root);
}

bst_node* bst_search(bst_node* root, const int data) {
    if (root == NULL) { return NULL; }
    if (root->data == data) {
        return root;
    }

    if (data < root->data) {
        return bst_search(root, data);
    }
    else if (data > root->data) {
        return bst_search(root, data);
    }

    return NULL;
}

void bst_copy(bst_node** copy, bst_node* orig) {
    if (orig == NULL) return;
    if (*copy == NULL) {
        *copy = bst_new_node(orig->data); 
    }
    bst_copy(&(*copy)->left, orig->left);
    bst_copy(&(*copy)->right, orig->right);
}

void inorder_print(bst_node* root) {
    if (root == NULL) return;
    inorder_print(root->left);
    printf("%d\n", root->data);
    inorder_print(root->right);

}

void preorder_print(bst_node* root) {
    if (root == NULL) return;
    printf("%d\n", root->data);
    preorder_print(root->left);
    preorder_print(root->right);

}

void postorder_print(bst_node* root) {
    if (root == NULL) return;
    postorder_print(root->left);
    postorder_print(root->right);
    printf("%d\n", root->data);

}

int bst_depth(bst_node* root) {
    if (root == NULL) return 0;
    int right_depth = bst_depth(root->right);
    int left_depth  = bst_depth(root->left);
    if (right_depth > left_depth)
        return right_depth+1;
    else
        return left_depth+1;
}

int bst_sum_leaves(bst_node* root) {
    if (root == NULL) return 0;
    int sum = 0;
    if (root->left == NULL && root->right == NULL) {
        sum += root->data;
    }
    sum += bst_sum_leaves(root->left);
    sum += bst_sum_leaves(root->right);

    return sum;
}

int bst_size(bst_node* root) {
    if (root == NULL) return 0;
    return 1 + bst_size(root->left) + bst_size(root->right);
}
