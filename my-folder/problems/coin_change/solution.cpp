class Solution {
public:
    int N;
    int dp[13][10101];
    vector<int> arr;

    int rec(int i, int amt){
        // cout<<i<<" "<<amt<<" "<<N<<endl;
        if(amt==0)    return 0;
        
        if(i>=N)    return 1e9;
        if(dp[i][amt]!=-1)  return dp[i][amt];
        int ans = -1;
        if(amt>=arr[i]){
            // cout<<"here"<<endl;
            ans = min(1+rec(i,amt-arr[i]),rec(i+1,amt));
        }
        else ans = rec(i+1,amt);
        // cout<<i<<" "<<amt<<" "<<ans<<endl;
        return dp[i][amt] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        N = coins.size();
        // cout<<N<<endl;
        sort(coins.begin(),coins.end(),greater<int>());
        arr = coins;
        memset(dp,-1,sizeof(dp));
        dp[0][amount] = rec(0,amount);
        
        // for(int i=0; i<=N; i++){
        //     for(int amt = 0; amt<=amount; amt++){
        //         cout<<dp[i][amt]<<" ";
        //     }cout<<endl;
        // }
        if(dp[0][amount]>=1e8)  return -1;
        return dp[0][amount];
    }
};