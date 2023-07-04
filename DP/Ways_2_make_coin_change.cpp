#include<bits/stdc++.h>

long solve(int index, int value, int *nums, vector<vector<long>> &dp){
    if(value == 0) return 1;
    
    if(index == 0){
        if(value % nums[index] == 0) return 1;
        return 0;
    }

    if(dp[index][value] != -1) return dp[index][value];

    long pick, not_pick;
    pick = not_pick = 0;

    if(nums[index] <= value) pick = solve(index, value - nums[index], nums, dp);
    not_pick = solve(index-1, value, nums, dp);

    return dp[index][value] = pick + not_pick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long> (value+1, -1));

    return solve(n-1, value, denominations, dp);
}