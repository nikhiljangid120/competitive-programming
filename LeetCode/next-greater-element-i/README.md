# next-greater-element-i

- **Platform:** LeetCode
- **Language:** C++

## Solution

```cpp
class Solution {
public:
   vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size();
       int n = nums2.size();
       stack<int>st;
       vector<int>v;
       unordered_map<int,int>mp;
       for(int i = n-1;i>=0;i--){
           while(!st.empty() && st.top()<=nums2[i]) st.pop();
           if(st.empty()) mp[nums2[i]] = -1;
           else mp[nums2[i]] = st.top();
           st.push(nums2[i]);
       }
       for (int i = 0; i < nums1.size(); i++) {
           v.push_back(mp[nums1[i]]);
       }
       return v;
   }
};
```
