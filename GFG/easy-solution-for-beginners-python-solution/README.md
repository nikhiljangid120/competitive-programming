# Easy solution for beginners | Python Solution

- **Platform:** GFG
- **Language:** C++

## Solution

```cpp
class Solution {
  public:
   int cntSubarrays(std::vector<int>& arr, int k) {
       // Map to store the frequency of unique prefix sums
       std::unordered_map<int, int> prefix_map;

       // Base case: a prefix sum of 0 has occurred 1 time (handles subarrays starting from index 0)
       prefix_map[0] = 1;

       int current_sum = 0;
       int count = 0;

       for (int num : arr) {
           current_sum += num;

           // Check if (current_sum - k) exists in our history
           if (prefix_map.find(current_sum - k) != prefix_map.end()) {
               count += prefix_map[current_sum - k];
           }

           // Record the current prefix sum in the map
           prefix_map[current_sum]++;
       }

       return count;
   }
};
```
