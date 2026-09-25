class Solution {
public:
   vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
       int n = nums.size();
       vector<int>temp;
       fun(ans, nums, 0, n);
       return ans;
   }
   void fun(vector<vector<int>>&ans, vector<int>&nums, int idx,
   int n){
       // BASE CASE
       if(idx == nums.size()){
           ans.push_back(nums);
           return;
       }
       for(int i = idx;i<n;i++){
           swap(nums[idx], nums[i]);
           fun(ans, nums, idx+1, n);
           swap(nums[i], nums[idx]);
       }
   }
};