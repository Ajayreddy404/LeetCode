class Solution {
public:
    int n,m;
    void rec(vector<vector<char>>& grid, int i, int j){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]=='2')    return;
        if(grid[i][j]=='0'){
            grid[i][j] = '2';
            return;
        }
        grid[i][j] = '2';
        rec(grid, i+1, j);
        rec(grid, i, j+1);
        rec(grid, i-1, j);
        rec(grid, i, j-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    rec(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

