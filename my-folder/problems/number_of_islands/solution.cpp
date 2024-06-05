class Solution {
public:
    // vector<vector<int>> [301];
    bool vis[301][301];
    int n,m;

    void dfs(int i, int j, vector<vector<char>>& grid){
        if(vis[i][j]==true || grid[i][j]=='0') return;
        vis[i][j] = true;
        if(i+1<n)   dfs(i+1,j,grid);
        if(j+1<m)   dfs(i,j+1,grid);
        if(i-1>=0)  dfs(i-1,j,grid);
        if(j-1>=0)   dfs(i,j-1,grid);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]=='1' && vis[i][j]==false){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        
        return cnt;
        
    }
};