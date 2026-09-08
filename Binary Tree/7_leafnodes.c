#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int leafnodes(struct node *root);

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
    printf("\nLeaf Nodes: ");
    int b=leafnodes(root);
    printf("%d",b);
    return 0;
}

int leafnodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return leafnodes(root->left) + leafnodes(root->right);
}
