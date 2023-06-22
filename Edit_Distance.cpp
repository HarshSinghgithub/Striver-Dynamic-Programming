int editDistance(string s, string t)
{
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int i=0; i<=m; i++) dp[0][i] = i;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]);
        }
    }

    return dp[n][m];
}