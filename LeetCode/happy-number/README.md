# happy-number

- **Platform:** LeetCode
- **Language:** C++

## Solution

```cpp
class Solution {
public:
   bool isHappy(int n) {
       int slow = n;
       int fast = happy(n);
       while(fast!=slow && fast!=-1){
           slow = happy(slow);
           fast = happy(happy(fast));
       }
       return fast == 1;
   }
   int happy(int n){
       int sum = 0;
       while(n>0){
           int digits = n%10;
           sum+=digits*digits;
           n/=10;
       }
       return sum;
   }
};
```
