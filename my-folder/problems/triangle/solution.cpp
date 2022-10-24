class Solution {
public:
    int n,m;
    vector<vector<int>> arr;
    int dp[202][202];

    int rec(int i, int j){
        if(i==n)    return 0;
        if(j>i) return 1e9;
        if(dp[i][j]!=-1)    return dp[i][j];

        int ans = arr[i][j] + min(rec(i+1,j), rec(i+1,j+1));
        return dp[i][j] = ans;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        arr = triangle;
        n = arr.size();
        m = arr[n-1].size();
        for(int i=0; i<=n; i++){
            for(int j=0; j<=i; j++){
                dp[i][j] = -1;
            }
        }

        int ans = rec(0,0);
        return ans;
    }
};