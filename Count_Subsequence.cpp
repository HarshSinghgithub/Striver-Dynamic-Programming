#include <bits/stdc++.h>

int mod = 1e9 + 7;

int solve(int ind1, int ind2, string s, string t, vector<vector<int>> &dp){
    if(ind2 < 0) return 1;
    if(ind1 < 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    int pick, not_pick;
    pick = not_pick = 0;

    if(s[ind1] == t[ind2]) pick = solve(ind1-1, ind2-1, s, t, dp);
    not_pick = solve(ind1-1, ind2, s, t, dp);

    return dp[ind1][ind2] = (pick + not_pick) %  mod;
}

int subsequenceCounting(string &s, string &t, int lt, int ls) {
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    return solve(n-1, m-1, s, t, dp);
} 