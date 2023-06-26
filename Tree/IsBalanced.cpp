class Solution {
public:

    int solve(TreeNode* root){
        if(!root) return 0;

        int lt = solve(root -> left);
        int rt = solve(root -> right);

        if(lt == -1 || rt == -1) return -1;

        if(abs(lt - rt) > 1) return -1;

        return 1 + max(lt, rt);
    }

    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};