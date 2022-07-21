class Solution {
public:
    int n;
    // bool vis;
    int dp[101];

    int rec(int level, int maxInd, vector<int>& arr){
        // cout<<level<<" "<<maxInd<<endl;
        if(level > maxInd)  return 0;

        if(dp[level]!=-1)   return dp[level];

        int ans = max(rec(level+2,maxInd,arr), rec(level+3,maxInd,arr)) + arr[level];

        // if(level==0)    vis = true;
        // cout<<level<<" "<<maxInd<<" "<<ans<<endl;
        return dp[level] = ans;
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        if(n<=3){
            int ans = 0;
            for(auto x: nums){
                ans = max(ans,x);
            }
            return ans;
        }
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,n-2,nums);
        // vis = false;
        for(int i=0; i<=n; i++) dp[i] = -1;
        ans = max(ans,max(rec(1,n-1,nums), rec(2,n-1,nums)));
        return ans;
    }
};