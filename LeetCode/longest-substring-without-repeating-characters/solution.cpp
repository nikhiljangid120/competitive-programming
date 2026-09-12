class Solution {
public:
   int lengthOfLongestSubstring(string s) {
       int n = s.size();
       int low = 0, maxLen = 0;
       unordered_map<char, int>mp;
       for(int high = 0;high<n;high++){
           mp[s[high]]++;
           while(mp[s[high]]>1){
               mp[s[low]]--;
               if(mp[s[low]]==0) mp.erase(s[low]);
               low++;
           }
           auto len = high - low + 1;
           maxLen = max(maxLen, len);
       }   
       return maxLen;
   }
};