class Solution {
public:
   vector<vector<int>> fourSum(vector<int>& nums, int target) {
       int n = nums.size();
       vector<vector<int>> result;
       if (n < 4) return result;  // Return if less than 4 elements
       
       sort(nums.begin(), nums.end());  // Sort the array
       
       for (int i = 0; i < n - 3; i++) {
           if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates for the first element
           
           for (int j = i + 1; j < n - 2; j++) {
               if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates for the second element
               
               int start = j + 1, end = n - 1;
               
               while (start < end) {
                   long long ans = (long long)nums[i] + nums[j] + nums[start] + nums[end];

                   
                   if (ans == target) {
                       result.push_back({nums[i], nums[j], nums[start], nums[end]});
                       
                       // Skip duplicates for `start` and `end`
                       while (start < end && nums[start] == nums[start + 1]) start++;
                       while (start < end && nums[end] == nums[end - 1]) end--;
                       
                       // Move both pointers after finding a match
                       start++;
                       end--;
                   } else if (ans < target) {
                       start++;  // Move the `start` pointer to increase the sum
                   } else {
                       end--;  // Move the `end` pointer to decrease the sum
                   }
               }
           }
       }
       
       return result;
   }
};