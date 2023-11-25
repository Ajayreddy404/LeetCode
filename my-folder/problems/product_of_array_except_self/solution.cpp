class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // technique: storing prefix product array and suffix product array in a single array
        
        // int n = nums.length;
        // int ans[] = new int[n];
        // Arrays.fill(ans, 1);
        // int curr = 1;
        // for(int i = 0; i < n; i++) {
        //     ans[i] *= curr;
        //     curr *= nums[i];
        // }
        // curr = 1;
        // for(int i = n - 1; i >= 0; i--) {
        //     ans[i] *= curr;
        //     curr *= nums[i];
        // }
        // return ans;



        int n = nums.size();
        long long int prod = 1;
        int cnt0 = 0;
        for(auto x: nums){
            if(x!=0)    prod *= x;
            if(x==0)    cnt0++;
        }

        vector<int> ans(n,0);
        if(cnt0==1){
            for(int i=0; i<n; i++){
                if(nums[i]==0)  ans[i] = prod;
            }
        }else if(cnt0==0){
            for(int i=0; i<n; i++){
                ans[i] = prod/nums[i];
            }
        }
        
        return ans;
    }
};