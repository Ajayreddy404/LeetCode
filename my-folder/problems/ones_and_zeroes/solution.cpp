#define F first
#define S second
class Solution {
public:
    int C0,C1,n;
    vector<pair<int,int>> arr;
    int dp[606][101][101];

    int rec(int level, int zeros, int ones){
        if(ones>C1 || zeros>C0)   return -1e9;
        if(level==n)    return 0;
        if(dp[level][zeros][ones]!=-1)  return dp[level][zeros][ones];
        // don't take
        int ans = rec(level+1,zeros,ones);
        // take this level
        ans = max(ans, 1+rec(level+1, zeros+arr[level].F, ones+arr[level].S));
        return dp[level][zeros][ones] = ans;
    }

    int findMaxForm(vector<string>& strs, int M, int N) {
        C0 = M;
        C1 = N;
        n = strs.size();
        arr = vector<pair<int,int>> (n);
        for(int i=0; i<n; i++){
            string S = strs[i];
            int cnt0 = 0, cnt1 = 0;
            for(char c: S){
                if(c=='0')  cnt0++;
                else    cnt1++;
            }
            arr[i] = make_pair(cnt0,cnt1);
        }

        memset(dp,-1,sizeof(dp));
        
        int ans = rec(0,0,0);
        return ans;
    }
};