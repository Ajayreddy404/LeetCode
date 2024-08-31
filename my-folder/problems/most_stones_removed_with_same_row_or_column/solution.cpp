class Solution {
public:

    void rec(vector<int>& s, vector<vector<vector<int>>>& grpx, vector<vector<vector<int>>>& grpy, vector<bool>& vis, int i){
        if(vis[i])  return;
        vis[i] = true;
        // traverse
        cout<<i<<s[0]<<s[1]<<endl;
        for(auto v: grpx[s[0]]){
            vector<int> vec = {v[0],v[1]};
            rec(vec, grpx, grpy, vis, v[2]);
        }
        for(auto v: grpy[s[1]]){
            vector<int> vec = {v[0],v[1]};
            rec(vec, grpx, grpy, vis, v[2]);
        }
        return;
    }


    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        // make a graph structure 
        // whether we can travel from one stone to another 
        // allowed paths: vertically or/and horizontally
        vector<vector<vector<int>>> grpx(1e4+1);
        vector<vector<vector<int>>> grpy(1e4+1);
        for(int i=0; i<n; i++){
            vector<int> s = stones[i];
            int x = s[0], y = s[1];
            vector<int> vec = {x,y,i};
            grpx[x].push_back(vec);
            grpy[y].push_back(vec);
        }

        vector<bool> vis(n,false);  //whether a stone has been visited or not

        // find the number of connected components
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(vis[i]==false){
                rec(stones[i],grpx,grpy,vis,i);
                cnt++;
            }
        }
        return n-cnt;
    }
};