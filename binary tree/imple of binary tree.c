// C program to implement binary search tree
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct BinaryTreeNode {
	int key;
	struct BinaryTreeNode *left, *right;
};

// Function to create a new node with a given value
struct BinaryTreeNode* newNodeCreate(int value)
{
	struct BinaryTreeNode* temp
		= (struct BinaryTreeNode*)malloc(
			sizeof(struct BinaryTreeNode));
	temp->key = value;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to search for a node with a specific key in the
// tree
struct BinaryTreeNode*
searchNode(struct BinaryTreeNode* root, int target)
{
	if (root == NULL || root->key == target) {
		return root;
	}
	if (root->key < target) {
		return searchNode(root->right, target);
	}
	return searchNode(root->left, target);
}

// Function to insert a node with a specific value in the
// tree
struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value)
{
	if (node == NULL) {
		return newNodeCreate(value);
	}
	if (value < node->key) {
		node->left = insertNode(node->left, value);
	}
	else if (value > node->key) {
		node->right = insertNode(node->right, value);
	}
	return node;
}

// Function to perform post-order traversal
void postOrder(struct BinaryTreeNode* root)
{
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf(" %d ", root->key);
	}
}

// Function to perform in-order traversal
void inOrder(struct BinaryTreeNode* root)
{
	if (root != NULL) {
		inOrder(root->left);
		printf(" %d ", root->key);
		inOrder(root->right);
	}
}

// Function to perform pre-order traversal


// Function to find the minimum value
struct BinaryTreeNode* findMin(struct BinaryTreeNode* root)
{
	if (root == NULL) {
		return NULL;
	}
	else if (root->left != NULL) {
		return findMin(root->left);
	}
	return root;
}

// Function to delete a node from the tree
struct BinaryTreeNode* delete (struct BinaryTreeNode* root,
							int x)
{
	if (root == NULL)
		return NULL;

	if (x > root->key) {
		root->right = delete (root->right, x);
	}
	else if (x < root->key) {
		root->left = delete (root->left, x);
	}
	else {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		else if (root->left == NULL
				|| root->right == NULL) {
			struct BinaryTreeNode* temp;
			if (root->left == NULL) {
				temp = root->right;
			}
			else {
				temp = root->left;
			}
			free(root);
			return temp;
		}
		else {
			struct BinaryTreeNode* temp
				= findMin(root->right);
			root->key = temp->key;
			root->right = delete (root->right, temp->key);
		}
	}
	return root;
}
void preOrder(struct BinaryTreeNode* root)
{
	if (root != NULL) {
		printf(" %d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
int height(struct BinaryTreeNode* t) {
    if (t == NULL)
        return 0;
	int lh = height(t->left);
	int rh = height(t->right);
    return (lh >= rh) ? lh + 1 : rh + 1;
}

int balanceFactor(struct BinaryTreeNode* t) {
    if (t == NULL)
        return 0;
    return height(t->left) - height(t->right);
}

void print(struct BinaryTreeNode* root, int level, char direction) {
    if (root != NULL) {
        print(root->right, level + 1, '/');
        for (int i = 0; i < level; i++)
            printf("    ");
            balanceFactor(root);
		printf("%c%d\n",direction,root->key);        
        print(root->left, level + 1, '\\');
    }
}

int main()
{
	// Initialize the root node
	struct BinaryTreeNode* root = NULL;

	// Insert nodes into the binary search tree
	root = insertNode(root, 5);
	insertNode(root, 3);
	insertNode(root, 2);
	insertNode(root, 4);
	insertNode(root, 7);
	insertNode(root, 1);
	insertNode(root, 9);
	insertNode(root, 6);
	insertNode(root, 8);
	print(root, 0, ' ');

	return 0;
}