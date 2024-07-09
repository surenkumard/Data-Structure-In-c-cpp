node delect(node root, int x){
    if(root == NULL){
        return NULL;
    }
    else if(x < root->info){
        root->left = delect(root->left, x);
    }
    else if(x > root->info){
        root->right = delect(root->right, x);
    }
    else{
        
    }
}