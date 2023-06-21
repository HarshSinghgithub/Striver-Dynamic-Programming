#include <bits/stdc++.h>

int solve(int index, int maxWeight, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(maxWeight == 0) return 0;

    if(index == 0) return (maxWeight / weight[index]) * profit[index];

    if(dp[index][maxWeight] != -1) return dp[index][maxWeight];

    int pick, not_pick;
    pick = not_pick = 0;

    if(maxWeight >= weight[index]) 
        pick = profit[index] + solve(index, maxWeight - weight[index], profit, weight, dp);
    not_pick = solve(index-1, maxWeight, profit, weight, dp);

    return dp[index][maxWeight] = max(pick, not_pick);
    
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int> (w+1, -1));

    return solve(n-1, w, profit, weight, dp);
}
