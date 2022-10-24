class Solution {
public:
    int n,m;
    vector<vector<int>> arr;
    int dp[202][202];
    vector<int> temp;

    int rec(int i, int j){
        if(i==n || j==m)    return 1e9;
        if(i==n-1 && j==m-1)    return arr[i][j];
        if(dp[i][j]!=-1)    return dp[i][j];
        int ans = arr[i][j] + min(rec(i+1,j), rec(i,j+1));
        return dp[i][j] = ans;
    }

    // void generate(int i, int j){

    // }

    int minPathSum(vector<vector<int>>& grid) {
        arr = grid;
        n = arr.size();
        m = arr[0].size();
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j] = -1;
            }
        }
        return rec(0,0);
        // print the path of min sum
        // generate();
        // for(auto x: temp){
        //     coout
        // }
    }
};