// #define double long double
class Solution {
public:

    void bfs(int node, vector<double>& pfa, vector<vector<pair<int,double>>>& adj, int N){
        priority_queue<pair<double, int>> pq;
        pq.push({1, node});   // node a
        
        while(!pq.empty()){
            int nd = pq.top().second;
            pq.pop();
            
            for(auto p: adj[nd]){
                if(pfa[p.first]<pfa[nd]*p.second){
                    pfa[p.first] = pfa[nd]*p.second;
                    pq.push({pfa[p.first],p.first});
                }
            }
        }
        return;
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int a, int b) {
        double ans = 0;
        vector<vector<pair<int,double>>> adj(n+1);
        // for(int i=0; i<=n; i++){
        //     adj[i][i] = 1;
        // }
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],prob[i]});
            adj[edges[i][1]].push_back({edges[i][0],prob[i]});
            // if(prob[i]==1)  cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
        }

        vector<double> pfa(n+1,0);  // prob from a (pfa)

        pfa[a] = 1;
        bfs(a,pfa,adj, n);
        ans = pfa[b];

        return ans;
    }
};