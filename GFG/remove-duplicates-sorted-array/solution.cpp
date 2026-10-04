class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = 0;
        for (int j = 1; j < n; j++) { 
            if (arr[i] != arr[j]) { 
                i++; 
                arr[i] = arr[j]; // Move the unique element forward
           } 
        } 
        arr.resize(i+1);       
        return arr;
    }
};