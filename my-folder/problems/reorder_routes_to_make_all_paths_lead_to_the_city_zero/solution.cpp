class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g1(n+1);
        vector<vector<int>> g2(n+1);
        
        for(int i=0; i<int(connections.size()); i++){
            g1[connections[i][0]].push_back(connections[i][1]);
            g2[connections[i][0]].push_back(connections[i][1]);
            g2[connections[i][1]].push_back(connections[i][0]);
        }
        
        queue<int> Q;
        vector<bool> vis(n+1,false);
        Q.push(0);
        int count = 0;
        while(!Q.empty()){
            int node = Q.front();
            vis[node]=true;
            Q.pop();
            
            for( auto x: g2[node]){
                if(vis[x])  continue;
                if(find(g1[node].begin(),g1[node].end(),x)==g1[node].end()){
                    count++;
                }
                Q.push(x);
            }
        }
        
        int ans = n-1-count;
        return ans;
    }
};