class Solution {
  public:
  
    int fun(int minDist, vector<int>&arr, int k){
        int n = arr.size();
        int cowPlaced = 1;
        int lastPos = arr[0];
        for(int i = 1;i<n;i++){
            if(arr[i] - lastPos >= minDist){
                cowPlaced++;
                lastPos = arr[i];
                if(cowPlaced>=k) return 1;
            }
        }
        return cowPlaced>=k;
    }
  
    int aggressiveCows(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int low = 1, high = arr.back() - arr.front();
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(fun(mid, arr, k)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};