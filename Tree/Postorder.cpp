class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* node = root;
        TreeNode* lastVisited = nullptr;  // keep track of the last visited node

        while (node != nullptr || !st.empty()) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            } else {
                TreeNode* topNode = st.top();
                
                // Check if the right subtree has been visited or not
                if (topNode->right && topNode->right != lastVisited) {
                    node = topNode->right;
                } else {
                    res.push_back(topNode->val);
                    lastVisited = topNode;
                    st.pop();
                }
            }
        }

        return res;
    }
};
