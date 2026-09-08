#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int countnodes(struct node *root);

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
    printf("\nCount nodes: ");
    int a=countnodes(root);
    printf("%d",a);
    return 0;
}

int countnodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    return 1+countnodes(root->left)+countnodes(root->right);
}
