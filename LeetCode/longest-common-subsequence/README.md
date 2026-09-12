# longest-common-subsequence

- **Platform:** LeetCode
- **Language:** C++

## Solution

```cpp
class Solution {
public:
   int longestCommonSubsequence(string text1, string text2) {
       int m = text1.size();
       int n = text2.size();
       vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
       return fun(text1, text2, dp, m, n, 0, 0);
   }
   int fun(string &text1, string&text2, vector<vector<int>>&dp, int m, 
   int n, int i, int j){
       if(i==m || j==n) return 0;

       if(dp[i][j]!=-1) return dp[i][j]; 

       if(text1[i]==text2[j]) 
           return dp[i][j] = 1 + fun(text1, text2, dp, m, n, i+1, j+1);

       else{
           int c1 = fun(text1, text2, dp, m, n, i+1, j);
           int c2 = fun(text1, text2, dp, m, n, i, j+1);
           return dp[i][j] = max(c1, c2);
       }
   }
};
```
