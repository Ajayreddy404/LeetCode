class Solution {
public:
    int n;
    int dp[100100];
    
    int rec(int level, vector<int>& arr){
        if(level>=n-1)  return 0;
        if(dp[level]!=-1)   return dp[level];
        int ans = 1e5;
        for(int i=arr[level]; i>0; i--){
            ans = min(ans, 1+rec(level+i,arr));
        }
        return dp[level] = ans;
    }
    
    int jump(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,nums);
    }
};