class Solution {
private:
   bool canSplit(long long maxAllowedSum, const vector<int>& nums, int k) {
       int subarraysCount = 1;
       long long currentSum = 0;

       for (int num : nums) {
           if (currentSum + num > maxAllowedSum) {
               subarraysCount++;   // Current subarray is full; start a new one
               currentSum = num;   // Start the new subarray with this number
           } else {
               currentSum += num;  // Fits in current subarray
           }
       }

       return subarraysCount <= k;
   }

public:
   int splitArray(vector<int>& nums, int k) {
       long long lo = *max_element(nums.begin(), nums.end());
       long long hi = accumulate(nums.begin(), nums.end(), 0LL);
       long long ans = hi;

       while (lo <= hi) {
           long long mid = lo + (hi - lo) / 2;

           if (canSplit(mid, nums, k)) {
               ans = mid;        // Target sum works; try to find a smaller maximum
               hi = mid - 1;
           } else {
               lo = mid + 1;     // Subarray sum is too small; increase limit
           }
       }

       return (int)ans;
   }
};