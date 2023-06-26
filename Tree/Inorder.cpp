class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* t = root;
        
        if(!root) return res;

        while(true){
            if(t != nullptr){
                st.push(t);
                t = t -> left;
            }
            else{
                if(st.empty()) break;
                t = st.top();
                st.pop();

                res.push_back(t -> val);
                t = t -> right;
            }
        }

        return res;
    }
};