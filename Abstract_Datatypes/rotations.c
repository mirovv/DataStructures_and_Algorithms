void leftRotate(Node* x){
    Node* r;

    r = x->right;
    x->right = r->left;
    r->parent = x->parent;

    if(r->left != NULL){
        r->left->parent = x;
    }
    if(x->parent == NULL){
        root = r;
    }else{
        if (x == x->parent->right){
            x->parent->right = r;
        }else{
            x->parent->left = r;
        }
    }
    r->left = x;
    x->parent = r;
}

voir rightRotate(Node* x){
    Node* r;

    r = x->left;
    x->left = r->left;
    r->parent = x->parent;

    if(r->right != NULL){
        r->right->parent = x;
    }
    if(x->parent == NULL){
        root = r;
    }else{
        if (x == x->parent->right){
            x->parent->right = r;
        }else{
            x->parent->left = r;
        }
    }
    r->right = x;
    x->parent = r;
}