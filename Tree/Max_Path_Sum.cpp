class Solution {
public:

    int solve(TreeNode* root, int &maxi){
        if(!root) return 0;

        int lt = max(0, solve(root -> left, maxi));
        int rt = max(0, solve(root -> right, maxi));

        maxi = max(maxi, root -> val + lt + rt);

        return root -> val + max(lt, rt);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root, maxi);

        return maxi;
    }
};