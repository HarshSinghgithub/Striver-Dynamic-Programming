int solve(int index, int tar, vector<int> nums, vector<vector<int>> &dp){
    if(tar == 0) return 1;
    
    if(index == 0) return nums[index] == tar;
    
    if(dp[index][tar] != -1) return dp[index][tar];
    
    int notPick = solve(index - 1, tar, nums, dp);
    
    int pick = 0;
    if(tar >= nums[index]) pick = solve(index - 1, tar - nums[index], nums, dp);
    
    return dp[index][tar] = pick + notPick;
}

int findWays(vector<int> &nums, int tar)
{
    vector<vector<int>> dp(nums.size(), vector<int> (tar + 1, -1));
    return solve(nums.size() - 1, tar, nums, dp);
}