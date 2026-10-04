# Move All Zeroes to the End of an Array

- **Platform:** GFG
- **Language:** C++

## Solution

```cpp
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 0;
        for(;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};
```
