class Solution {
public:
    int n;
    vector<vector<int>> g;
    vector<bool> vis;
    
    void dfs(int node){
        if(vis[node])   return;
        vis[node] = true;
        
        for(auto x: g[node]){
            dfs(x);
        }
        
        return;
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<int> p(2);
        
        for(int i=n-1; i>=0; i--){
            g.clear();
            vis.clear();
            g.resize(n+1);
            vis.resize(n+1,false);
            
            for(int j=0; j<n; j++){
                if(i==j)    continue;
                g[edges[j][0]].push_back(edges[j][1]);
                g[edges[j][1]].push_back(edges[j][0]);
            }
            
            dfs(1);
            bool flag = true;
            for(int j=1; j<=n; j++){
                if(!vis[j]) flag = false;
            }
            
            if(flag){
                p = edges[i];
                return p;
            }
        }
        
        
        return p;
    }
};