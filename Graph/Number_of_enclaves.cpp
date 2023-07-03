class Solution {
public:

    bool boundaryCheck(int row, int col, int n, int m){
        return (row > -1 && col > -1 && row < n && col < m);
    }

    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis){
        if(vis[row][col] == 1 || grid[row][col] == 0) return;

        vis[row][col] = 1;

        vector<int> dir_row{-1, 0, 1, 0};
        vector<int> dir_col{0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int new_row = row + dir_row[i];
            int new_col = col + dir_col[i];

            if(boundaryCheck(new_row, new_col, grid.size(), grid[0].size()) && vis[new_row][new_col] == 0){
                dfs(new_row, new_col, grid, vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i=0; i<n; i++){
            if(grid[i][0] == 1){
                dfs(i, 0, grid, vis);
            }

            if(grid[i][m-1] == 1){
                dfs(i, m-1, grid, vis);
            }
        }

        for(int i=0; i<m; i++){
            if(grid[0][i] == 1){
                dfs(0, i, grid, vis);
            }

            if(grid[n-1][i] == 1){
                dfs(n-1, i, grid, vis);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    count++;
                }
            }
        }

        return count;
    }
};