#include <bits/stdc++.h>

int solve(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp) {
  if (row == 0)
    return mat[row][col];

  if (dp[row][col] != -1)
    return dp[row][col];

  int path1, path2, path3;
  path1 = path2 = path3 = INT_MIN;

  path1 = mat[row][col] + solve(row - 1, col, mat, dp);
  if (col > 0)
    path2 = mat[row][col] + solve(row - 1, col - 1, mat, dp);
  if (col < mat[0].size() - 1)
    path3 = mat[row][col] + solve(row - 1, col + 1, mat, dp);

  return dp[row][col] = max(max(path1, path2), path3);
}

int getMaxPathSum(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int max_sum = INT_MIN;

  vector<vector<int>> dp(n, vector<int>(m, -1));

  for (int i = 0; i < m; i++) {
    max_sum = max(max_sum, solve(n - 1, i, matrix, dp));
  }

  return max_sum;
}