class Solution {
public:
    int n;
    int dp[201][1001];
    // returns the number of combinations from nums[level] to nums[n-1] that sums upto t
    int rec(int level, int t, vector<int>& nums){
        if(t==0)    return 1;
        if(level==n)    return 0;
        if(dp[level][t]!=-1)    return dp[level][t];
        // transition
        int ans = 0;
        if(t<nums[level])   ans = 0;
        else{
            ans = rec(0,t-nums[level],nums) + rec(level+1,t,nums);
        }
        return dp[level][t] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,target,nums);
        return ans;
    }
};