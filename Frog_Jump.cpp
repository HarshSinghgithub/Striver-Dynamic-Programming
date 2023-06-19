#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<int> &heights, vector<int> &dp){
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];

    int jump1 = abs(heights[index] - heights[index-1]) + solve(index-1, heights, dp);
    int jump2 = INT_MAX;

    if(index > 1){
        jump2 = abs(heights[index] - heights[index-2]) + solve(index-2, heights, dp);
    }

    return dp[index] = min(jump1, jump2);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    
    return solve(n-1, heights, dp);
}