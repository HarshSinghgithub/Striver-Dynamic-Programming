#include<bits/stdc++.h>
using namespace std;

bool solve(int index, int tar, vector<int> &nums, vector<int> &dp){
    if(tar == 0) return true;

    if(index == 0) return nums[index] == tar;

    if(dp[index] != -1) return dp[index];

    bool pick, not_pick;
    pick = not_pick = false;
    

    if(tar >= nums[index]) pick = solve(index-1, tar - nums[index], nums, dp);
    not_pick = solve(index-1, tar, nums, dp);

    return dp[index] = pick || not_pick;
}

bool canPartition(vector<int> &nums, int n)
{
    int sum = 0;
    for(int num : nums) sum += num;

    cout<<sum<<endl;

    if(sum%2 != 0) return false;

    vector<int> dp(n, -1);

    return solve(n-1, sum/2, nums, dp);
}

int main(){
    vector<int> vec{80, 78, 64, 88, 37, 45, 92, 47, 40, 27, 13, 42, 30, 36, 41, 28, 72, 38, 99, 69};
    cout<<canPartition(vec, 20);
    return 0;
}