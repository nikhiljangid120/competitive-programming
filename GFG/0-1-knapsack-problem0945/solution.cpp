class Solution {
  public:
  
    int solve(int capacity, vector<int> &val, vector<int> &weight, int i, vector<vector<int>> & table){
        
        if (i < 0 or capacity == 0){
            return 0;
        }
        
        if (table[i][capacity] != -1){
            return table[i][capacity];
        }
        
        if (capacity < weight[i]){
            table[i][capacity] = solve(capacity, val, weight, i-1, table);
            return table[i][capacity]; 
        }
        
        else{
            int first = solve(capacity, val, weight, i-1, table);
            
            int new_capacity = capacity - weight[i];
            int second = val[i] + solve(new_capacity, val, weight, i-1, table);
            
            table[i][capacity] = max({first , second});
            return table[i][capacity]; 
        }
        
        return table[i][capacity];
    }
  
    int knapsack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        std::vector<std::vector<int>> table(n, std::vector<int>(capacity + 1, -1));
        
        return solve(capacity, val, wt, n-1, table);
    }
};