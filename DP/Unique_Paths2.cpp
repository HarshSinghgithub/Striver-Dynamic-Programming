int mod = 1e9 + 7;

int solve(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp) {
  if (row < 0 || col < 0 || mat[row][col] == -1)
    return 0;

  if (row == 0 && col == 0)
    return 1;

  if (dp[row][col] != -1)
    return dp[row][col];

  int up = solve(row - 1, col, mat, dp);
  int left = solve(row, col - 1, mat, dp);

  return dp[row][col] = (up + left) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
  vector<vector<int>> dp(n, vector<int>(m, -1));

  return solve(n - 1, m - 1, mat, dp);
}