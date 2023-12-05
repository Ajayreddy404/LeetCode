class Solution {
public:
    int n,m;
    int dp[1001][1001];

    // returns the max len subseq in s1[l1], s2[l2]
    int rec(int l1, int l2, string& s1, string &s2){
        if(l1==n || l2==m)  return 0;
        if(dp[l1][l2]!=-1)  return dp[l1][l2];
        int ans = 0;
        if(s1[l1]==s2[l2])  ans = 1+rec(l1+1,l2+1,s1,s2);
        else{
            ans = max(rec(l1+1,l2,s1,s2), rec(l1,l2+1,s1,s2));
        }
        return dp[l1][l2] = ans;
    }

    int longestCommonSubsequence(string s1, string s2) {
        n = s1.length();
        m = s2.length();
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,0,s1,s2);
        return ans;
    }
};