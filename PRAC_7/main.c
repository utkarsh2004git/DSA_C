#include <stdio.h>
#include <stdlib.h>

struct BST{
    int data;
    struct BST *left;
    struct BST *right;
};
struct BST *root; 
struct BST* create(struct BST *root ,int value){
    if(root==NULL){
        root=(struct BST *)malloc(sizeof(struct BST));
        root->data=value;
        root->left=root->right=NULL;
        return root;
    }
    else{
        printf("Root is already exists");
        return NULL;
    }
}
struct BST*  insertion(struct BST *root,int data){
    if (root == NULL) {
        return create(root,data);
    }

    if(root!=NULL){
        if(data<root->data){
            root->left=insertion(root->left,data);
        }
        else if(data>root->data){

         root->right=   insertion(root->right,data);
        }
        else{
            printf("Can not Insert!\n");
            return NULL;
        }
        return root;
    }
    
}
void inorderTraversal(struct BST* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(struct BST* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct BST* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
int main(){
    root = insertion(root, 50);
    insertion(root, 30);
    insertion(root, 20);
    insertion(root, 40);
    insertion(root, 70);
    insertion(root, 60);
    insertion(root, 80);
    printf("Inorder Traversal :");
    inorderTraversal(root);
    printf("\nPreorder Traversal :");
    preorderTraversal(root);
    printf("\nPostorder Traversal :");
    postorderTraversal(root);
    return 0;
}
