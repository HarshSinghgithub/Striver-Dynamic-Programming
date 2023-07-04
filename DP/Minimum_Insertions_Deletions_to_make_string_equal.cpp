#include <bits/stdc++.h>

int lcs(string s, string t){
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int canYouMake(string &str, string &ptr)
{
    int res = lcs(str, ptr);
    int n = str.length();
    int m = ptr.length();

    return (n - res) + (m - res);
}



