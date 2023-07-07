bool isLeaf(TreeNode<int>* node){
    return (!node -> left && !node -> right);
}

void addLeftBound(TreeNode<int>* root, vector<int>& ans){
    root = root->left;
    while(root){
        if(!isLeaf(root)) ans.push_back(root->data);
        if(root->left) root = root->left;
        else root = root->right;
    }
}

void addRightBound(TreeNode<int>* root, vector<int>& ans){
    root = root->right;
    stack<int> st;
    while(root){
        if(!isLeaf(root)) st.push(root->data);
        if(root->right) root = root->right;
        else root = root->left;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}


void addLeaves(TreeNode<int>* root, vector<int>& ans){
    if(root==NULL){
        return;
    }
    if(isLeaf(root)){
        ans.push_back(root->data); //just store leaf nodes
        return;
    }
    addLeaves(root->left,ans);
    addLeaves(root->right,ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data); 
    addLeftBound(root,ans);
    addLeaves(root,ans);
    addRightBound(root,ans);
    
    return ans;
}