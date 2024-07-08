class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int td) {
        vector<vector<long long>> dist(n,vector<long long>(n,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)    continue;
                dist[i][j] = INT_MAX;
            }
        }
        for(auto e : edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][j] > dist[i][k]+dist[k][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                        dist[j][i] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }

        int scity = 0, pcnt = 100000;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j]<=td)   cnt++;
            }
            if(cnt<=pcnt){
                scity = i;
                pcnt = cnt;
                cout<<cnt<<" "<<scity<<endl;
            }
        }
        return scity;
    }
};