#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);

struct node *create_bt() {
    struct node *p;
    int key;

    printf("\nEnter the key value: ");
    scanf("%d", &key);

    if (key == -1) {
        return NULL;
    }

    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    p->data = key;

    printf("\nEnter the left child of key: %d", key);
    p->left = create_bt();

    printf("\nEnter the right child of key: %d", key);
    p->right = create_bt();

    return p;
}

int main() {
    struct node *root;

    root = create_bt();

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d->", root->data);
    }
}
