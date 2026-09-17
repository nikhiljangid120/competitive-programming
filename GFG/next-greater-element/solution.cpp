class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>v;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]) st.pop();
            if(st.empty()) v.push_back(-1) ;
            else v.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};