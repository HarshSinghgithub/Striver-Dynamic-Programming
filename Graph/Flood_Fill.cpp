class Solution {
public:

    void dfs(int row, int col, int oldColor, int newColor, vector<vector<int>> &grid, vector<vector<int>> &vis){
        if(vis[row][col] == 1) return;
        
        vis[row][col] = 1;
        
        if(grid[row][col] != oldColor) return;
        
        grid[row][col] = newColor;
        
        if(row > 0){
            dfs(row-1, col, oldColor, newColor, grid, vis);
        }
        
        if(row < vis.size()-1){
            dfs(row+1, col, oldColor, newColor, grid, vis);
        }
        
        if(col > 0){
            dfs(row, col-1, oldColor, newColor, grid, vis);
        }
        
        if(col < vis[0].size()-1){
             dfs(row, col+1, oldColor, newColor, grid, vis);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        dfs(sr, sc, oldColor, newColor, image, vis); 
        
        return image;
    }
};