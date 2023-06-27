vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int, int> mpp;
    queue<pair<BinaryTreeNode<int>*, int>> qu;
    vector<int> res;

    if(!root) return res;

    qu.push({root, 0});

    while(!qu.empty()){
        int n = qu.size();

        for(int i=0; i<n; i++){
            auto itr = qu.front();
            qu.pop();
            
            BinaryTreeNode<int>* node = itr.first;
            int col = itr.second;

            mpp[col] = node -> data;

            if(node -> left) qu.push({node -> left, col-1});
            if(node -> right) qu.push({node -> right, col+1});
        }
    }

    for(auto it : mpp){
        res.push_back(it.second);
    }

    return res;    
}