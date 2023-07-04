// User function Template for C++

class Solution {
  public:
  
    bool boundaryCheck(int row, int col, int n, int m){
        return (row > -1 && row < n && col > -1 && col < m);
    }
  
    void dfs(int row, int col, int brow, int bcol, vector<pair<int, int>> &ds, vector<vector<int>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        ds.push_back({row - brow, col - bcol});
        
        vector<int> dir_row{-1, 0, 1, 0};
        vector<int> dir_col{0, 1, 0, -1};
        
        for(int i=0; i<4; i++){
            int new_row = row + dir_row[i];
            int new_col = col + dir_col[i];
            
            if(boundaryCheck(new_row, new_col, grid.size(), grid[0].size()) && vis[new_row][new_col] == 0 && grid[new_row][new_col] == 1){
                dfs(new_row, new_col, brow, bcol, ds, grid, vis);
            }
        }
        
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        set<vector<pair<int, int>>> st;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    vector<pair<int, int>> ds;
                    dfs(i, j, i, j, ds, grid, vis);
                    st.insert(ds);
                }
            }
        }
        
        return st.size();
    }
};