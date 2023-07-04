#include<bits/stdc++.h>

bool solve(int index, int tar, vector<int> &nums, vector<vector<int>> &dp){
    if(tar == 0) return true;

    if(index == 0) return nums[index] == tar;

    if(dp[index][tar] != -1) return dp[index][tar];

    bool pick, not_pick;
    pick = not_pick = false;
    
    if(tar >= nums[index]) pick = solve(index-1, tar - nums[index], nums, dp);
    not_pick = solve(index-1, tar, nums, dp);

    return dp[index][tar] = pick || not_pick;
}

bool canPartition(vector<int> &nums, int n)
{
    int sum = 0;
    for(int num : nums) sum += num;

    if(sum%2 != 0) return false;

    int tar = sum/2;

    vector<vector<int>> dp(n, vector<int> (tar+1, -1));

    return solve(n-1, tar, nums, dp);
}
