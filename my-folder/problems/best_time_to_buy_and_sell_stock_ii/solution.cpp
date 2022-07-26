class Solution {
public:
    int maxProfit(vector<int>& arr) {
        // sum(local max - just prev local min)
        int ans = 0, n = arr.size();
        for(int i=0; i<n; ){
            int minv = 1e5, maxv = -1;
            while(i<n && minv>arr[i]){
                minv = arr[i];
                i++;
            }
            while(i<n && maxv<arr[i]){
                maxv = arr[i];
                i++;
            }
            
            if(maxv!=-1)    ans += abs(maxv-minv);
        }
        return ans;
    }
};