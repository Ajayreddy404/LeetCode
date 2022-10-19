class Solution {
public:
    int n;
    vector<vector<int>> grp;
    int dep[20020];
    bool vis[20020];
    int par[20020];

    void dfs(int node, int parent, int depth){
        // cout<<node<<" "<<parent<<" "<<depth<<endl;
        vis[node] = 1;
        dep[node] = depth;
        par[node] = parent;
        for(int nd: grp[node]){
            if(nd==parent)  continue;
            if(!vis[nd])    dfs(nd,node,depth+1);
        }
        return;
    }

    vector<int> findMinHeightTrees(int N, vector<vector<int>>& edges) {
        vector<int> ans;
        n = N;
        grp = vector<vector<int>>(n);
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            grp[a].push_back(b);        // 0 to n-1 node numbers
            grp[b].push_back(a);        // not 1 to n.
        }

        // for(auto v: grp){
        //     for(auto x: v){
        //         cout<<x<<" ";
        //     }cout<<endl;
        // }

        int maxdep = 0, nd = 0;
        dfs(0,-1,0);    // {node,par,depth}
        for(int i=0; i<n; i++){
            if(dep[i]>maxdep){
                maxdep = dep[i];
                nd = i;
            }
        }
        // for(int i=0; i<n; i++){
        //     cout<<dep[i]<<" ";
        // }cout<<endl;

        // 
        int dia = 0;
        memset(vis,0,sizeof(vis));
        dfs(nd,-1,0);

        for(int i=0; i<n; i++){
            if(dep[i]>dia){
                dia = dep[i];
                nd = i;
            }
        }
        // for(int i=0; i<n; i++){
        //     cout<<dep[i]<<" ";
        // }cout<<endl;

        int k = dia/2;
        while(k--){
            nd = par[nd];
        }
        ans.push_back(nd);
        if(dia%2==1){       // even nodes on tthe diameter, two centers.
            ans.push_back(par[nd]);
        }

        return ans;


    }
};