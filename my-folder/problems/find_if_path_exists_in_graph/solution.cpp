class Solution {
public:
    
    void dfs(int n, vector<vector<int>> &g, vector<bool> &vis, int i){
        if(vis[i])  return;
        vis[i] = true;
        
        
        for(auto x : g[i]){
            dfs(n,g,vis,x);
        }
        
        
        return;
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // make the graph
        vector<vector<int>> g(n);
        for(auto p : edges){
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        
        vector<bool> vis(n,false);
        dfs(n,g,vis,source);
        
        if(vis[destination]){
            return true;
        }
        return false;
    }
};