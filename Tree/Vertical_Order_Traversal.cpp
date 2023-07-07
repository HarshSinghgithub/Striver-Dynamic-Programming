vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> verPos;
        queue<pair<TreeNode*, pair<int, int>>> qu;
        
        qu.push(make_pair(root, make_pair(0, 0)));
        
        while(!qu.empty()){
            auto currPtr = qu.front();
            qu.pop();
            TreeNode* currRoot = currPtr.first;
            int x = currPtr.second.first;
            int y = currPtr.second.second;
            
            verPos[y][x].insert(currRoot -> val);
            
            if(currRoot -> left){
                qu.push(make_pair(currRoot -> left, make_pair(x + 1, y - 1)));
            }
            
            if(currRoot -> right){
                qu.push(make_pair(currRoot -> right, make_pair(x + 1, y + 1)));
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto i : verPos){
            vector<int> vec;
            for(auto j : i.second){
                vec.insert(vec.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(vec);
        }
        return ans;
    } 