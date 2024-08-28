class Solution {
public:
    
    void rec(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool& flag, int m, int n){
        if(i>=m || j>=n || i<0 || j<0)  return;
        if(grid2[i][j]==0)  return;
        if(grid1[i][j]==0)  flag = false;
        grid2[i][j] = 0;
        // cout<<i<<" "<<j<<endl;
        rec(grid1,grid2,i,j+1,flag,m,n);
        rec(grid1,grid2,i+1,j,flag,m,n);
        rec(grid1,grid2,i,j-1,flag,m,n);
        rec(grid1,grid2,i-1,j,flag,m,n);
        return;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        int m = grid1.size();
        int n = grid1[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                bool flag = true;
                if(grid2[i][j]==1){
                    // cout<<i<<" "<<j<<endl;
                    rec(grid1,grid2,i,j,flag,m,n);
                    if(flag)    ans++;
                }
                
            }
        }
        return ans;
    }
};