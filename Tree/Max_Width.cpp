int widthOfBinaryTree(TreeNode* root) {
        int width = INT_MIN;
        queue<pair<TreeNode*, int>> qu;
        
        qu.push({root, 0});
        
        while(!qu.empty()){
            int n = qu.size();
            int min = qu.front().second;
            int first,last;
            
            for(int i=0; i<n; i++){
                auto p = qu.front();
                qu.pop();
                
                TreeNode* temp = p.first;
                int index = p.second - min;
                if(i == 0) first = index;
                if(i == n-1) last = index;
                
                if(temp -> left) qu.push({temp -> left, (2 * index) + 1});
                if(temp -> right) qu.push({temp -> right, (2 * index) + 2});
            }
            width = max(width, last - first + 1);
        }
        
        return width;
    }