class Solution {
public:
    int n;
    // int arr;
    int dp[101];
    
    int rec(int level, vector<int>& arr){
        if(level>=n){
            return 0;
        }
        
        if(dp[level]!=-1){
            return dp[level];
        }
        
        int ans = max(rec(level+2, arr), rec(level+3, arr)) + arr[level];
        
        return dp[level] = ans;
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n = nums.size();
        int ans = max(rec(0,nums), rec(1,nums));
        return ans;
    }
};