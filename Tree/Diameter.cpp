class Solution {
public:

    int solve(TreeNode* root, int &maxi){
        if(!root) return 0;

        int lt = solve(root -> left, maxi);
        int rt = solve(root -> right, maxi);

        maxi = max(maxi, lt + rt);

        return 1 + max(lt, rt);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;

        solve(root, maxi);

        return maxi; 
    }
};