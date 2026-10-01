1
2
3
4
5
6
7
10
12
8
9
11
13
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(auto i = 0 ; i<n ; i++){
            int comp = target - nums[i];
        }
    }
            if(mp.find(comp)!=mp.end()) return {mp[comp], i};
            mp[nums[i]] = i;
        return {};
};