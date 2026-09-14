# valid-anagram

- **Platform:** LeetCode
- **Language:** C++

## Solution

```cpp
1
2
3
4
8
5
6
7
9
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return 0;
    }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
};
No results
```
