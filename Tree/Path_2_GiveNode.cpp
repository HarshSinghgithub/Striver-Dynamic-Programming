 bool fun(treenode* root, vector<int> &ans, int x){
     if(!root)
     return false;
     
     ans.push_back(root -> val);
     
     if(root -> val == x) return true;
     
     if(fun(root -> left, ans, x) || fun(root -> right, ans, x)) return true;
     
     ans.pop_back();
     return false;
 }
 
int* solve(treenode* A, int B, int *len1) {
    int vec;
    
    fun(root, vec, B);
    
    return vec;
}