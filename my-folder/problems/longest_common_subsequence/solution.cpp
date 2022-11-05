class Solution {
public:
    string s1, s2;
    int n = s1.length(), m = s2.length();
    int dp[1001][1001];

    int rec(int i, int j){
        if(i==n || j==m){
            return 0;
        }
        if(dp[i][j]!=-1)    return dp[i][j];

        int ans = 0;
        if(s1[i]==s2[j]){
            ans = 1+rec(i+1,j+1);
        }else{
            ans = max(rec(i+1,j), rec(i,j+1));
        }

        return dp[i][j] = ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        n = s1.length();
        m = s2.length();
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j] = -1;
            }
        }
        int ans = rec(0,0);
        return ans;
    }
};