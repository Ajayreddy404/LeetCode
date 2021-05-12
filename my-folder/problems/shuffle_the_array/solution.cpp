class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shf_arr(2*n);
        for(int i = 0; i<n; i++){
            shf_arr[2*i] = nums[i];
            shf_arr[2*i+1] = nums[n+i];
        }
        return shf_arr;
    }
};