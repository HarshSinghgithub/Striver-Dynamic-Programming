class Solution {
public:

    void fill_dp(string s, string t, vector<vector<int>> &dp){
        int n = s.length();
        int m = t.length();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string printSupersequence(string s, string t, vector<vector<int>> &dp){
        int i = s.length();
        int j = t.length();
        string res = "";

        while(i > 0 && j > 0){
            if(s[i-1] == t[j-1]){
                res += s[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] < dp[i][j-1]){
                    res += t[j-1];
                    j--;
                }
                else{
                    res += s[i-1];
                    i--;
                }
            }
        }

        while(i > 0) res += s[--i];
        while(j > 0) res += t[--j];

        reverse(res.begin(), res.end());
        return res;
    }

    string shortestCommonSupersequence(string a, string b) {
        int n = a.length();
        int m = b.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        fill_dp(a, b, dp);
        
        return printSupersequence(a, b, dp);
    }
};