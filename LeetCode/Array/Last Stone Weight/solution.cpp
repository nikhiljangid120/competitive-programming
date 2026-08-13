class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq; // We need a max heap here
        for(auto x:stones) pq.push(x);
        while(pq.size()>=2){
            int x = pq.top(); // Largest element
            pq.pop();
            int y = pq.top(); // Second Largest Element
            pq.pop();   
            if(y!=x) pq.push(x-y);
        }
        if(!pq.empty()) return pq.top();
        return 0;
    }
};