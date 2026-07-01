class Solution {
public:
    int n;
    // DFS Approach
    // void dfs(vector<bool>&visited, int i, unordered_map<int,vector<int>>&mp){
    //     visited[i] = true;
    //     for(int &v:mp[i]){
    //         if(!visited[v]) dfs(visited,v,mp);
    //     }
    // }

    // BFS Approach
    void bfs(vector<bool>&visited, int i, unordered_map<int,vector<int>>&mp){
        queue<int>q;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            for(int &v:mp[temp]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]==1&&i!=j){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,false);
        int counter = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                // dfs(visited,i,mp);
                bfs(visited,i,mp);
                counter++;
            }
        }
        return counter;
    }
};