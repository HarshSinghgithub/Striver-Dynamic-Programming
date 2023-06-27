class Solution {
public:

    bool solve(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;

        if(!root1 || !root2) return false;

        if(root1 -> val != root2 -> val) return false;

        return solve(root1 -> left, root2 -> right) && solve(root1 -> right, root2 -> left);
    }

    bool isSymmetric(TreeNode* root) {
        return solve(root -> left, root -> right);
    }
};