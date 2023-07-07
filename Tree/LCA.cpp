TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q){
            return root;
        }

        TreeNode* lt = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rt = lowestCommonAncestor(root -> right, p, q);

        if(lt == nullptr){
            return rt;
        }
        else if(rt == nullptr){
            return lt;
        }
        else{
            return root;
        }
    }