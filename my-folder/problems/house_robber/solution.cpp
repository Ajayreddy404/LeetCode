class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //nums.push_back(0);
        //vector<int> dp(n);
        if(n==1){
            return nums[0];
        }
        else if(n==2){
            return max(nums[0],nums[1]);
        }
        else if(n==3){
            return max(nums[0]+nums[2],nums[1]);
        }
        
        int first = nums[0], second = nums[1], curr = nums[0]+nums[2];

        for(int i=3; i<n; i++){
            int temp = max(first,second) + nums[i];
            first = second;
            second = curr;
            curr = temp;
            
        }
        
        return max(curr,second);
    }
};