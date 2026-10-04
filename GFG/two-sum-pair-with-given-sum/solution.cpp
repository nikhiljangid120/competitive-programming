class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int>mp;
          for(int i = 0;i<n;i++) {
            int comp = target - arr[i];
            if(mp.find(comp)!=mp.end()) return 1;
            mp[arr[i]] = i;
        }
        return {};
    }
};