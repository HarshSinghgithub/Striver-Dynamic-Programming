#include <bits/stdc++.h>

int solve(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
    if(ind == prices.size() || cap == 0){
        return 0;
    }

    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    if(buy){
        return dp[ind][buy][cap] = max(
                                    -prices[ind] + solve(ind+1, 0, cap, prices, dp), 
                                    solve(ind+1, 1, cap, prices, dp)
                                    );
    }
    
    return dp[ind][buy][cap] = max(
                                    prices[ind] + solve(ind+1, 1, cap-1, prices, dp)
                                    ,solve(ind+1, 0, cap, prices, dp)
                                );
}

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));

    return solve(0, 1, 2, prices, dp);
}

// Tabulation

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, 0)));

    for(int i=n-1; i>=0; i++){
        for(int j=0; j<2; j++){
            for(int k=1; k<3; k++){
                if(j == 1){
                    dp[i][j][k] = max(-prices[i] + dp[i+1][0][k], dp[i+1][1][k]);
                }
                else{
                    dp[i][j][k] = max(prices[i] + dp[ind+1][1][k-1], dp[i+1][1][k-1], dp[ind+1][0][k]);
                }
            }
        }
    }

    return solve(0, 1, 2, prices, dp);
}