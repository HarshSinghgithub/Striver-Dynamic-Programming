#include<bits/stdc++.h>

long getMaximumProfit(long *values, int n)
{
    vector<long> prev(2, 0);
    vector<long> curr(2, 0);

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=1; j++){
            if(j == 1) curr[j] = max(-values[i] + prev[0], prev[1]);
            else curr[j] = max(values[i] + prev[1], prev[0]);
            prev[j] = curr[j];
        }
    }

    return curr[1];
}