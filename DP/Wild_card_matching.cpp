#include<bits/stdc++.h>

int solve(int ind1, int ind2, string text, string pat, vector<vector<int>> &dp){
   if(ind1 < 0 && ind2 < 0) return true;

   if(ind2 < 0 && ind1 >= 0) return false;
   
   if(ind1 < 0 && ind2 >= 0){
      if(pat[ind2] == '*') 
         return solve(ind1, ind2-1, text, pat, dp);
      return false;
   }

   if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

   if(text[ind1] == pat[ind2] || pat[ind2] == '?') 
      return dp[ind1][ind2] = solve(ind1-1, ind2-1, text, pat, dp);
   
   if(pat[ind2] == '*') 
      return dp[ind1][ind2] = solve(ind1, ind2-1, text, pat, dp) || 
                              solve(ind1-1, ind2, text, pat, dp);

   return dp[ind1][ind2] = false;
}

bool wildcardMatching(string pattern, string text)
{
   int n = text.length();
   int m = pattern.length();

   vector<vector<int>> dp(n, vector<int> (m, -1));

   return solve(n-1, m-1, text, pattern, dp);
}
