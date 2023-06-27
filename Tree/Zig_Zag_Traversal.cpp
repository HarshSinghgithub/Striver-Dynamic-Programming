class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> qu;
        bool l2r = true;

        if(root == nullptr) return res;

        qu.push(root);

        while(!qu.empty()){
            int n = qu.size();
            vector<int> ds(n);

            for(int i=0; i<n; i++){
                TreeNode* node = qu.front();
                qu.pop();

                int index = (l2r) ? i : n - 1 - i;
                ds[index] = node -> val;

                if(node -> left) qu.push(node -> left);
                if(node -> right) qu.push(node -> right);
            }

            l2r = !l2r;
            res.push_back(ds);
        }

        return res;
    }
};