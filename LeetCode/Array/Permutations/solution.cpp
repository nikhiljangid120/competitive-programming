class Solution {
public:
    unordered_set<int>ansSet;
    vector<vector<int>>answer;
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int>temp;
        solve(temp,nums);
        return answer;
    }
    void solve(vector<int>&temp, vector<int>&nums){
        if(temp.size()==nums.size()){
            answer.push_back(temp);
            return;
        }
        for(int i = 0;i<n;i++){
            if(ansSet.find(nums[i])==ansSet.end()){
                temp.push_back(nums[i]);
                ansSet.insert(nums[i]);
                solve(temp,nums);
                temp.pop_back();
                ansSet.erase(nums[i]);
            }
        }
    }
};