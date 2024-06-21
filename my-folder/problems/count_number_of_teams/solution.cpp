class Solution {
public:
    int getTeamsCount(vector<int>& arr){
        int n = arr.size();
        int dp[n][3];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }

        for(int i=1; i<n; i++){
            // for dp[i][1]
            for(int j=0; j<i; j++){
                if(arr[j]<arr[i]){
                    dp[i][1]+=dp[j][0];
                }
            }

            // for dp[i][2]
            for(int k=0; k<i; k++){
                if(arr[k]<arr[i]){
                    dp[i][2]+=dp[k][1];
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += dp[i][2];
        }
        return ans;
    }

    int numTeams(vector<int>& arr) {
        int cnt = getTeamsCount(arr);
        reverse(arr.begin(),arr.end());
        cnt += getTeamsCount(arr);
        return cnt;
    }
};