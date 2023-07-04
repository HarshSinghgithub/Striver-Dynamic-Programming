#include <bits/stdc++.h>

int solve(int row, int col, vector<vector<int>> triangle, vector<vector<int>> & dp){
    if(row == triangle.size()-1) return triangle[row][col];

    if(dp[row][col] != -1) return dp[row][col];

    int path1, path2;
    
    path1 = triangle[row][col] + solve(row+1, col, triangle, dp);

    path2 = triangle[row][col] + solve(row+1, col+1, triangle, dp);

    return dp[row][col] = min(path1, path2);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int> (n, -1));

    return solve(0, 0, triangle, dp);
}