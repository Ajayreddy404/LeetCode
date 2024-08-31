class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> arr(2*n-1);
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i<n; i++){
            arr[i] = gas[i]-cost[i];
            sum1 += gas[i];
            sum2 += cost[i];
        }
        if(sum1<sum2){
            return -1;
        }

        for(int i=n; i<2*n-1; i++){
            arr[i] = arr[i-n];
        }

        vector<int> dp(2*n,0);
        int ans = 0;
        for(int i=2*n-2; i>=0; i--){
            dp[i] = max(arr[i], dp[i+1]+arr[i]);
            if(dp[i]>dp[ans])   ans = i;
        }
        return ans%n;

    }
};