# 21. number-of-substrings-containing-all-three-characters

- **Platform:** LeetCode
- **Language:** code

## Solution

```
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0, j = 0, count = 0;
        unordered_map<char, int>mp;
        while(j<n){
            mp[s[j]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
                count+=(n-j);
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
```
