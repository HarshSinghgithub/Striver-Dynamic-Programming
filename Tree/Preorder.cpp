class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        
        if(!root) return res;

        st.push(root);

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();

            res.push_back(temp -> val);
            if(temp -> right) st.push(temp -> right);
            if(temp -> left) st.push(temp -> left);
        }

        return res;
    }
};