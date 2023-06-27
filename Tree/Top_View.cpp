vector<int> getTopView(TreeNode<int> *root) {
    map<int, int> mpp;
    queue<pair<TreeNode<int>*, int>> qu;
    vector<int> res;

    if(!root) return res;

    qu.push({root, 0});

    while(!qu.empty()){
        int n = qu.size();

        for(int i=0; i<n; i++){
            auto itr = qu.front();
            qu.pop();
            
            TreeNode<int>* node = itr.first;
            int col = itr.second;

            if(mpp.find(col) == mpp.end()){
                mpp[col] = node -> val;
            }

            if(node -> left) qu.push({node -> left, col-1});
            if(node -> right) qu.push({node -> right, col+1});
        }
    }

    for(auto it : mpp){
        res.push_back(it.second);
    }

    return res;
}