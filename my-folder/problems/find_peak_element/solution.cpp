class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i=1; i<n && n>1; i++){
            if(i==0){
                if(nums[i] > nums[i+1])
                    result = i;
            }
            else if(i==n-1){
                if(nums[i]>nums[i-1])
                    result = i;
            }
            else{
                if((nums[i]>nums[i-1]) && (nums[i]>nums[i+1]))
                    result = i;
            }
        }
        return result;
    }
};