class Solution {
public:

    int solve(int index, vector<int> &nums, vector<int> &dp){
        if(index < 0) return 0;
        
        if(index == 0) return nums[index];

        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + solve(index-2, nums, dp);
        int not_pick = solve(index-1, nums, dp);

        return dp[index] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        
        temp = nums;
        temp.erase(temp.begin());

        int ans1 = solve(n-2, nums, dp1);
        int ans2 = solve(temp.size()-1, temp, dp2);

        return max(ans1, ans2);
    }
};