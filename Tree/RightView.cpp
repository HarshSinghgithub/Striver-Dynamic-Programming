class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        qu.push(root);
        
        while(!qu.empty()){
            int n = qu.size();
            
            for(int i=0; i<n; i++){
                TreeNode* temp = qu.front();
                qu.pop();
                
                if(i == n-1) ans.push_back(temp -> val);
                
                if(temp -> left) qu.push(temp -> left);
                
                if(temp -> right) qu.push(temp -> right);
            }
        }
        return ans;
    }
};