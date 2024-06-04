class Solution {
public:
    int n, dp[101];
    int rec(int level, vector<int>& nums){
        if(level>=n)    return 0;
        if(dp[level]!=-1)   return dp[level];
        int ans = max(nums[level] + rec(level+2,nums), rec(level+1,nums));
        return dp[level] = ans;
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        if(n==1)    return nums[0];
        memset(dp,-1,sizeof(dp));
        int ans = max(rec(0,nums), rec(1,nums));
        return ans;
    }
};