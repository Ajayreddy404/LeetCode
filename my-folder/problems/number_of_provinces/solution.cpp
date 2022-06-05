class Solution {
public:
    int n;
    vector<vector<int>> g;
    vector<bool> vis;
    
    void dfs(int i){
        if(vis[i])  return;
        vis[i] = true;
        
        for(auto x: g[i]){
            dfs(x);
        }
        
        return;
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        n = isConnected.size();
        
        g.resize(n+1);
        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && isConnected[i][j]){
                    g[i+1].push_back(j+1);
                }
            }
        }
        
        vis.resize(n+1,false);
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                count++;
                dfs(i);
            }
        }
        
        return count;
    }
};