#include <bits/stdc++.h>

int mod = 1e9 + 7;

int solve(int index, int tar, vector<int> &nums, vector<vector<int>> &dp){
        if(index == 0){
            if(nums[index] == 0 && tar == 0) return 2;
            if(tar == 0 || nums[index] == tar) return 1;
            return 0;
        }

        if(dp[index][tar] != -1) return dp[index][tar];

        int pick, not_pick;
        pick = not_pick = false;

        if(nums[index] <= tar) pick = solve(index-1, tar - nums[index], nums, dp);
        not_pick = solve(index-1, tar, nums, dp);

        return dp[index][tar] = (pick + not_pick) % mod;
    }

int countPartitions(int n, int d, vector<int> &nums) {
    int tot_sum = 0;

    for(int num : nums){
        tot_sum += num;
    }

    if((tot_sum - d) % 2 != 0 || tot_sum - d < 0) return 0;

    int target = (tot_sum - d)/2;
    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    
    return solve(n-1, target, nums, dp) % mod;
}