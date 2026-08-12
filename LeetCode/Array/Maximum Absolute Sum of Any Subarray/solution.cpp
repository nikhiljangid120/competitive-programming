class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = abs(nums[0]), currSum = nums[0], mini = nums[0], maxi = nums[0];
        for(int i = 1;i<n;i++){
            int v1 = nums[i];
            int v2 = nums[i] + maxi;
            int v3 = nums[i] + mini;
            maxi = max(v1, v2);
            mini = min(v1, v3);
            currSum = max(currSum, max(abs(maxi), abs(mini)));
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};