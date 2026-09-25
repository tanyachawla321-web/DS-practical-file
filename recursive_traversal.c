#include <stdio.h>
#include <stdlib.h>
// Define a structure for a binary tree node
struct Node {
 int data;
 struct Node* left;
 struct Node* right;
};
// Function to create a new binary tree node
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}
// Function to build a binary tree using user input
struct Node* buildTree() {
 int data;
printf("Enter data (or -1 for empty node): ");
scanf("%d", &data);
 if (data == -1) {
 return NULL;
 }
 struct Node* root = createNode(data);
printf("Enter left child of %d:\n", data);
 root->left = buildTree();
printf("Enter right child of %d:\n", data);
 root->right = buildTree();
 return root;
}// Function for pre-order traversal
void preOrder(struct Node* root) {
 if (root != NULL) {
printf("%d ", root->data);
 preOrder(root->left);
 preOrder(root->right);
 }
}
// Function for in-order traversal
void inOrder(struct Node* root) {
 if (root != NULL) {
 inOrder(root->left);
printf("%d ", root->data);
 inOrder(root->right);
 }
}
// Function for post-order traversal
void postOrder(struct Node* root) {
 if (root != NULL) {
 postOrder(root->left);
 postOrder(root->right);
printf("%d ", root->data);
 }
}
int main() {
 struct Node* root = NULL;
printf("Enter the elements of the binary tree:\n");
 root = buildTree();
printf("Binary Tree Traversals:\n");
printf("Pre-order traversal: ");
 preOrder(root);
 printf("\n");
printf("In-order traversal: ");
 inOrder(root);
 printf("\n");
printf("Post-order traversal: ");
 postOrder(root);
 printf("\n");
 // Free memory (optional)
 // You can add code here to free the dynamically allocated memory for the tree
 return 0;
}
 