class Solution {
public:
    bool makesquare(vector<int>& arr) {
        int N = arr.size();
        int target = 0;
        for(int i=0; i<N; i++){
            target += arr[i];
        }
        if(target%4!=0) return false;

        target /= 4;        // k = 4
        int dp[(1<<N)];
        for(int i=0; i<(1<<N); i++){
            dp[i] = -1;
        }

        dp[0] = 0;

        for(int mask=0; mask<(1<<N); mask++){
            if(dp[mask]==-1)    continue;
            for(int i=0; i<N; i++){
                // note that this if will execute only when sum <= target
                // when sum > target, it will consider this case
                if( ( !((mask>>i)&1) ) && dp[mask]+arr[i]<=target){
                    dp[mask|(1<<i)] = (dp[mask]+arr[i])%target;
                }
            }
        }

        if(dp[(1<<N)-1]==0){
            return true;
        }
        return false;
    }
};