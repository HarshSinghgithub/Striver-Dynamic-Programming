#include<bits/stdc++.h>
using namespace std;

int solve(int index, vector<int> &dp){
	if(index < 3) return index;

	if(dp[index] != -1) return dp[index];

	int way1 = solve(index-1, dp);
	int way2 = solve(index-2, dp);

	return dp[index] = way1 + way2;
}

int countDistinctWays(int n){
	vector<int> dp(n+1, -1);

	return solve(n, dp);
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		cout<<countDistinctWays(n);
	}
	return 0;
}