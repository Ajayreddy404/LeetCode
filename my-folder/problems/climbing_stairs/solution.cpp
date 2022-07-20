class Solution {
public:
    
    int N;
    int dp[50];
    
    int rec(int level){
        // base case and pruning
        if(level > N){
            return 0;
        }
        if(level==N){
            return 1;
        }
        
        // cache check
        if(dp[level]!=-1)   return dp[level];
        
        // transit and calc
        int ans = rec(level+1) + rec(level+2);
        
        // save and return
        return dp[level] = ans;
    }
    
    int climbStairs(int n) {
        N = n;
        memset(dp,-1,sizeof(dp));
        return rec(0);
    }
};