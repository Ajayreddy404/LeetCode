class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        vector<int> r_sum(nums.size()+1);
        
        r_sum[0] = 0;
        for(int i=0; i<nums.size(); i++){
            r_sum[i+1] = r_sum[i] + nums[i];
        }
        if(nums.size()!=0){
            int max_sum = r_sum[1];
            int len = r_sum.size();
            for(int i =0; i < len; i++){

                for(int j =i+1; j < len; j++){

                    if(r_sum[j]-r_sum[i] > max_sum){
                        max_sum = r_sum[j]-r_sum[i];

                    }
                }

            }
            return max_sum;
        }
        else
            return 0;
        
        
    }
};