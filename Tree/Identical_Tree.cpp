class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        if(!p || !q) return false;

        bool lt = isSameTree(p-> left, q -> left);
        bool rt = isSameTree(p -> right, q -> right);

        return (p -> val == q -> val && lt && rt);
    }
};