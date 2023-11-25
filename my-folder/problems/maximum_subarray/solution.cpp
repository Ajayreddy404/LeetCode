class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();

        int psum[n+1]; psum[0] = 0;
        for(int i=1; i<=n; i++){
            psum[i] = psum[i-1] + arr[i-1];
        }

        int mn = 0;
        int ans = psum[1];
        for(int i=1; i<=n; i++){
            if(i!=1)    ans = max(ans, psum[i]-mn);
            mn = min(mn, psum[i]);
        }

        return ans;
        
    }
};