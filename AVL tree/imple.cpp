#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        Node* left;
        Node* right;
        int height;
};

Node* Balance(Node* root){
    int bal = getBalance(root);

    if(bal > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }

    if(bal > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(bal < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }

    if(bal < -1 && getBalance(root->right) > 0){
        root->right = leftRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int height(Node* root){
    return (root == NULL) ? 0 : root->height;
}

int max(int a, int b){
    return (a > b) ? a : b; 
}

int getBalance(Node* root){
    return (root == NULL) ? 0 : (height(root->left) - height(root->right));
}

Node* leftRotate(Node* root){
    Node* x = root->right;
    Node *temp = root->left;
    x->left = root;
    root->right = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(root->left), height(root->right)) + 1;

    return x;
}

Node* rightRotate(Node* root){
    Node* x = root->left;
    Node* temp = x->right;
    x->right = root;
    root->left = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(root->left), height(root->right)) + 1;

    return x;
}

Node* insert(Node* root, int key){
    if(root == NULL){
        return newNode(key);
    }

    if(key < root->key){
        root->left = insert(root->left, key);
    }
    else if(key > root->key){
        root->right = insert(root->right, key);
    }
    else{
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    return Balance(root);    
}

Node* minValue(Node* root){
    if(root == nullptr){
        return NULL;
    }
    return (root->left == nullptr) ? root : minValue(root->left);
}


Node* deleteANode(Node* root,int key){
    if(root == NULL){
        return root;
    }
    else if(root->key > key){
        root->left = deleteANode(root->left, key);
    }
    else if(root->key < key){
        root->right = deleteANode(root->right, key);
    }
    else{
        if(root->left && root->right){
            Node* temp = minValue(root->right);
            root->key = temp->key;
            root->right = deleteANode(root->right, root->key);
        }

        else{
            if(root->left == NULL || root->right == NULL){
                Node *temp;
                if(root->left == NULL){
                    temp = root->right;
                }
                else if(root->right == NULL){
                    temp = root->left;
                }
                delete root;
                return temp;
            }
            else{
                delete root;
                return NULL;
            }
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    return Balance(root);
}

int main(){
    int num, input;
    cout << "Enter a number of node That you want to insert : ";
    cin >> num;

    Node* root = NULL;
    for(int i = 0; i < num; i++){
        cout << "Enter a number : ";
        cin >> input;
        root = insert(root, input);
    }

    return 0;
}