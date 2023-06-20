class Solution {
public:

    int solve(int index, int tar, vector<int> &nums, vector<vector<int>> &dp){
        if(index < 0) return 0;
        
        if(tar == 0) return 1;

        if(index == 0) return nums[index] == tar;

        if(dp[index][tar] != -1) return dp[index][tar];

        bool pick, not_pick;
        pick = not_pick = false;

        if(nums[index] <= tar) pick = solve(index-1, tar - nums[index], nums, dp);
        not_pick = solve(index-1, tar, nums, dp);

        return dp[index][tar] = pick + not_pick;
    }

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (k+1, -1));

        return solve(n-1, k, nums, dp);
    }
};