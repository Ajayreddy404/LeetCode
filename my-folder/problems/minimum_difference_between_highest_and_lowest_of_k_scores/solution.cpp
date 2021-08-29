class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int min_diff = INT_MAX;
        
        for(int i=0,j=k-1; j<nums.size(); i++, j++){
            if(min_diff > nums[j]-nums[i]){
                min_diff = nums[j] - nums[i];
            }
        }
        
        return min_diff;
        
    }
};