class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int minp = arr[0];
        int ans = 0;
        for(int i=1; i<n; i++){
            ans = max(ans,arr[i]-minp);
            minp = min(minp,arr[i]);
        }
        return ans;
    }
};