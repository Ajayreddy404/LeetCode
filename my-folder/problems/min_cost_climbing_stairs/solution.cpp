class Solution {
public:
    int n;
    // vector<int> arr;
    int dp[1010];
    
    int rec(int level, vector<int>& cost){
        // base case and pruning
        if(level > n){
            return 1e9;
        }
        if(level==n){
            return 0;
        }

        // cache check
        if(dp[level]!=-1)   return dp[level];

        // transit and calc
        int ans = min(rec(level+1, cost),rec(level+2, cost)) + cost[level];
        // cout<<level<<" "<<ans<<endl;

        // save and return
        return dp[level] = ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // arr = cost;
        n = cost.size();
        memset(dp,-1,sizeof(dp));
        return min(rec(0,cost),rec(1,cost));
    }
};