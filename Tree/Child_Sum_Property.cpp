void changeTree(BinaryTreeNode < int > * root) {
    if(root == nullptr) return;

    int child_sum = 0;

    if(root -> left){
        child_sum += root -> left -> data;
    }

    if(root -> right){
        child_sum += root -> right -> data;
    }

    if(child_sum >= root -> data){
        root -> data = child_sum;
    }
    else{
        if(root -> left) root -> left -> data = root -> data;
        if(root -> right) root -> right -> data = root -> data;
    }

    changeTree(root -> left);
    changeTree(root -> right);

    int tot = 0;

    if(root -> left){
        tot += root -> left -> data;
    }

    if(root -> right){
        tot += root -> right -> data;
    }

    if(root -> left || root -> right){
        root -> data = tot;
    }