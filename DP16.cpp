#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int> &nums, int n)
{
	int sum = 0;
    for(int num : nums) sum += num;
    
    vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));

    for(int i=0; i<n; i++) dp[i][0] = 1;
    if(nums[0] <= sum) dp[0][nums[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++){
            bool pick, not_pick;
            pick = not_pick = false;
            
            if(nums[i] <= j) pick = dp[i-1][j - nums[i]];
            not_pick = dp[i-1][j];

            dp[i][j] = pick || not_pick;
        }
    }

    int mini = INT_MAX;
    int k = sum/2;
    
    for(int i=0; i<=k; i++){
        if(dp[n-1][i]){
            mini = min(mini, abs(i - (sum-i)));
        }
    }

    return mini;
}
