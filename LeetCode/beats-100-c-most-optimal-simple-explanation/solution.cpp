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
1
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        int minDist = abs(nums[0]);
        for (int num : nums) {
            int dist = abs(num);
            if (dist < minDist || (dist == minDist && num > closest)) {
                closest = num;
                minDist = dist;
            }
        }
        return closest;
    }
class Solution {