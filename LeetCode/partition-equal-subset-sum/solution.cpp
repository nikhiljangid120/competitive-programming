class Solution {
public:
   bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int sum = 0;
       for(auto x:nums) sum+=x;
       if(sum%2!=0) return 0;
       int k = sum / 2;
       vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
       dp[n][0] = 1;
       for(int i = n-1;i>=0;i--){
           for(int j = 0;j<=k;j++){
               if(nums[i]>j) dp[i][j] = dp[i+1][j];
               else{
                   bool c1 = dp[i+1][j-nums[i]];
                   bool c2 = dp[i+1][j];
                   dp[i][j] = c1 or c2;
               }
           }
       }
       return dp[0][k];
   }
};