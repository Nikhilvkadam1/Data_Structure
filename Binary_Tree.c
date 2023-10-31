#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode() {
    int x;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1) {
        free(newNode);
        return NULL;
    }

    newNode->data = x;
    printf("Enter left child of %d: ", x);
    newNode->left = createNode();
    printf("Enter right child of %d: ", x);
    newNode->right = createNode();

    return newNode;
}
void inOrderTraversal(struct node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
void preOrderTraversal(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void PrintTree (struct node* root, int i){
    if(root==NULL){
      return;
  }
    PrintTree(root->right,i+1);

    for(int j=0 ;j<i; j++){
       printf("\t");
  }
    printf("%d" ,  root->data);
    printf("\n");
    PrintTree(root->left,i+1);
}



int main() {
    struct node *root = createNode();
    printf("In-order traversal result: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal result: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal result: ");
    postOrderTraversal(root);
    printf("\n");
    printf("\n");
    printf("\n");

    PrintTree(root , 0);


    return 0;
}
