class Solution {
  public:
    typedef long long ll;
    
    bool fun(ll maxLimit, vector<int>&arr, int k){
        ll partitions = 1;
        ll currentSum = 0;
        for(auto x: arr){
            if(x + currentSum > maxLimit){
                partitions++;
                currentSum = x;
            }
            else currentSum+=x;
        }
        return partitions<=k;
    }
    
    int minTime(vector<int>& arr, int k) {
        ll low = *max_element(arr.begin(), arr.end());
        ll high = accumulate(arr.begin(), arr.end(), 0ll);
        ll ans = high;
        while(low<=high){
            ll mid = low + (high-low)/2;
            if(fun(mid, arr, k)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};