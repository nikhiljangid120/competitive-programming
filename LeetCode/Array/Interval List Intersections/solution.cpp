class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();
        vector<vector<int>>res;
        int i = 0, j = 0;
        while(i<m && j<n){
            int s1 = firstList[i][0];
            int e1 = firstList[i][1];
            int s2 = secondList[j][0];
            int e2 = secondList[j][1]; 
            int s = max(s1, s2);
            int e = min(e1, e2);
            if(s<=e) res.push_back({s, e});
            if(e1<=e2) i++;
            else j++;
        }
        return res;
    }
};