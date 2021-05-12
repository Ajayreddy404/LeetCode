class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> op(2);
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    op[0] = i;
                    op[1] = j;
                    break;
                }
            }
        }
        
        return op;
    }
};