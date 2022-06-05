class Solution {
public:
    int n;
    vector<bool> vis;
    
    void dfs(int node, vector<vector<int>>& rooms){
        if(vis[node])   return;
        vis[node]=true;
        
        for(auto x: rooms[node]){
            dfs(x, rooms);
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vis.resize(n,false);
        
        dfs(0,rooms);
        
        for(int i=0; i<n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};