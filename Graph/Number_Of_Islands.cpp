class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){
        if(vis[row][col] == 1) return;
        
        vis[row][col] = 1;
        
        if(grid[row][col] == '0') return;
        
        if(row > 0){
            dfs(row-1, col, grid, vis);
            
            if(col > 0)
                dfs(row-1, col-1, grid, vis);
                
            if(col < vis[0].size()-1)
                dfs(row-1, col+1, grid, vis);
        }
        
        if(row < vis.size()-1){
            dfs(row+1, col, grid, vis);
            
            if(col > 0)
                dfs(row+1, col-1, grid, vis);
                
            if(col < vis[0].size()-1)
                dfs(row+1, col+1, grid, vis);
        }
        
        if(col > 0) dfs(row, col-1, grid, vis);
        
        if(col < vis[0].size()-1) dfs(row, col+1, grid, vis);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        
        return count;
    }
};