void solve(vector<int> &nums, vector<int> &dp, int i, int &n){
    if(i>=n){
        return;
    }
    //if(dp[i]!= -1){
    //    return dp[i];
    //}
    int j;
    for(j=1; j<=nums[i] && i+j<n; j++){
        dp[i+j] = min(dp[i+j], 1+dp[i]);
        //cout<<i+j<<" : "<<dp[i+j]<<endl;
    }
    solve(nums,dp,i+1, n);
    
    
}

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        vector<int> dp(n+1,100000);
        dp[0] = 0;
        solve(nums, dp, 0, n);
        return dp[n-1];
    }
};