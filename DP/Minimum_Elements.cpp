#include <bits/stdc++.h>

int solve(int index, int tar, vector<int> &nums, vector<vector<int>> &dp){
    if(tar == 0) return 0;

    if(index == 0){
        if(tar % nums[index] == 0) return tar/nums[index];
        return 1e9;
    }

    if(dp[index][tar] != -1) return dp[index][tar];

    int pick, not_pick;
    pick = not_pick = 1e9;

    if(tar >= nums[index]) pick = 1 + solve(index, tar - nums[index], nums, dp);
    not_pick = solve(index-1, tar, nums, dp);

    return dp[index][tar] = min(pick, not_pick);
}

int minimumElements(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (x+1, -1));

    int res = solve(n-1, x, nums, dp);

    return (res >= 1e9) ? -1 : res;
}