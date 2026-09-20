# Kth Smallest Element in a Sorted Matrix

- **Platform:** LeetCode
- **Language:** C++

## Solution

```cpp
1
2
3
4
5
6
7
8
12
9
11
14
10
13
15
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<int>pq;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
        }
                pq.push(matrix[i][j]);
            }
    }
                if(pq.size()>k) pq.pop();
        return pq.top();
};
```
