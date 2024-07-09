#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
        int val;
        Node *left;
        Node *right;
};  

Node* leftRotate(Node *y){
    Node *x = y->right;
    Node *temp = x->left;

    x->left = y;
    y->right = temp;

    return x;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    return x;
}

Node* splay(Node* root, int key){
    if(root == nullptr || root->val == key){
        return root;
    }

    if(root->val > key){
        if(root->left == nullptr){
            return root;
        }

        if(root->left->val > key){
            root->left->left = splay(root->left->left, key);

            root = rightRotate(root);
        }
        else{
            root->left->right = splay(root->left->right, key);

            if(root->left->right != nullptr){
                root->left = leftRotate(root->left);
            }
        }

        root = (root->left == nullptr) ? root : rightRotate(root);
    }
    else{
        if(root->right == nullptr){
            return root;
        }
        if(root->right->val > key){
            root->right->left = splay(root->right->left, key);

            if(root->right->left != nullptr){
                root->right = rightRotate(root->right);
            }
        }
        else{
            root->right->right = splay(root->right->right, key);

            root = leftRotate(root);
        }
        root = (root->right == nullptr) ? root : leftRotate(root);
    }

    return root;
}

Node* create(int key){
    Node* newNode = new Node;
    newNode->val = key;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, int key){
    if(root == nullptr){
        return create(key);
    }

    root = splay(root, key);

    if(root->val == key){
        return root;
    }

    Node* node = create(key);

    if(root->val > key){
        Node *temp = root->left;
        node->right = root;
        node->left = temp;
        root->left = nullptr;
    }
    else{
        Node *temp = root->right;
        node->left = root;
        node->right = temp;
        root->right = nullptr;
    }

    return node;
}

void print(Node* root, int index){
    if(root == nullptr){
        return;
    }
    int indentation = 5;
    print(root->right, index + indentation);
    cout << setw(index) << root->val << endl << endl;
    print(root->left, index + indentation);
}

// removing the key
Node* delete_key(Node* root, int key)
{
    Node* temp;
    if (!root)
        return NULL;
 
    // Splay the given key
    root = splay(root, key);
 
    // If key is not present, then
    // return root
    if (key != root->val)
        return root;
 
    // If key is present
    // If left child of root does not exist
    // make root->right as root
    if (!root->left) {
        temp = root;
        root = root->right;
    }
 
    // Else if left child exits
    else {
        temp = root;
 
        /*Note: Since key == root->key,
        so after Splay(key, root->lchild),
        the tree we get will have no right child tree
        and maximum node in left subtree will get splayed*/
        // New root
        root = splay(root->left, key);
 
        // Make right child of previous root as
        // new root's right child
        root->right = temp->right;
    }
 
    // free the previous root node, that is,
    // the node containing the key
    free(temp);
 
    // return root of the new Splay Tree
    return root;
}

int main(){
    int n;
    cout << "Enter a number of node : ";
    cin >> n;

    Node* root = nullptr;
    int val;
    for(int i = 0; i < n; i++){
        cout << "\n\nEnter a val : \n\n";
        cin >> val;
        root = insert(root, val);
        print(root, 0);
    }

    return 0;
}