class Solution {
public:
    int n;
    vector<int> arr;
    int dp[100100];

    int rec(int level){
        if(level > n){
            return 0;
        }
        if(dp[level]!=-1)   return dp[level];

        int ans = arr[level] + max(rec(level+2),rec(level+3));

        return dp[level] = ans;
    }

    int deleteAndEarn(vector<int>& nums) {
        n = 0;
        for(auto x: nums){
            n = max(x,n);
        }
        memset(dp,-1,sizeof(dp));
        arr.resize(n+1,0);
        for(auto x: nums){
            arr[x] += x;
        }
        // for(auto x: arr){
        //     cout<<x<<" ";
        // }cout<<endl;
        int ans = max(rec(1),rec(2));
        return ans;
    }
};