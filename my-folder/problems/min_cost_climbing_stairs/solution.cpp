/*void solve(int &n, vector<int> &dp, vector<int> &cost, int i){
    if(i==0)
        return;
    else if(i==1){
        dp[i] = dp[i-1]
    }
}*/


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //cost.push_back(0);
        //vector<int> dp(n+1,1e8);
        int first = cost[0], second = cost[1],temp;
        
        for(int i=2; i<n; i++){
            temp = min(first,second)+cost[i];
            first = second;
            second = temp;
        }
        
        return min(first,second);
    }
};