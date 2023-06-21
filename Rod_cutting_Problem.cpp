int solve(int index, int maxL, vector<int> &price, vector<vector<int>> &dp){
    if(maxL == 0) return 0;

    if(index == 0){
        return maxL * price[0];
    }

    if(dp[index][maxL] != -1) return dp[index][maxL];

    int pick, not_pick;
    pick = not_pick = 0;

    if(maxL >= index + 1) pick = price[index] + solve(index, maxL - (index + 1), price, dp);
    not_pick = solve(index-1, maxL, price, dp);

    return dp[index][maxL] = max(pick, not_pick);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int> (n+1, -1));

    return solve(n-1, n, price, dp);
}
