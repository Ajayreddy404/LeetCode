class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
        int n = arr.size();
        vector<int> arr2(n);
        arr2[0] = arr[0];
        for(int i=1; i<n; i++){
            arr2[i] = max(arr2[i-1],arr[i]+i);
        }
        int ans = 0;
        for(int i=1; i<n; i++){
            ans = max(arr[i]-i+arr2[i-1],ans);
        }
        return ans;
    }
};