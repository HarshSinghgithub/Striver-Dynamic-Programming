#include <bits/stdc++.h>

int solve(int index, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
    if(maxWeight == 0) return 0;
    
    if(index == 0){
        if(weight[index] <= maxWeight) return value[index];
        return 0;
    }

    if(dp[index][maxWeight] != -1) return dp[index][maxWeight];
    
    int pick, not_pick;
    pick = not_pick = 0;

    if(weight[index] <= maxWeight) 
        pick = value[index] + solve(index-1, maxWeight - weight[index], weight, value, dp);
    not_pick = solve(index-1, maxWeight, weight, value, dp);

    return dp[index][maxWeight] = max(pick, not_pick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));

    return solve(n-1, maxWeight, weight, value, dp);
}