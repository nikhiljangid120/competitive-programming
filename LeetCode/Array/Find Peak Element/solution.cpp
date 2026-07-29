class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return bs(nums, 0 , nums.size()-1); 
    }
    int bs(vector<int>& nums, int low, int high){
        if(low == high){
            return low;
        }
        int mid = (low + high) >> 1;
        if(nums[mid] > nums[mid+1]){
            return bs(nums, low, mid);
        }
        else{
            return bs(nums, mid+1, high);
        }
    }
};