#include <bits/stdc++.h>

int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(row == 0 && col == 0) return grid[row][col];

    if(dp[row][col] != -1) return dp[row][col];

    int up, left;
    up = left = INT_MAX;
    
    if(row > 0) up = grid[row][col] + solve(row-1, col, grid, dp);

    if(col > 0) left = grid[row][col] + solve(row, col-1, grid, dp);

    return dp[row][col] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    return solve(n-1, m-1, grid, dp);
}