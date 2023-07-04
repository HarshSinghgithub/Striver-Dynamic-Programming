#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mini = 1e9 + 1;
    int max_profit = 0;

    for(int price : prices){
        mini = min(mini, price);
        max_profit = max(max_profit, price - mini);
    }

    return max_profit;
}