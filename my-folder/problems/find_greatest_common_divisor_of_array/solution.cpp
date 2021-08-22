class Solution {
public:
    int findGCD(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int num1 = nums[0], num2 = nums[0]; //min and max respectively
        //finding num1 and num2 in nums
        for(int i=1; i<(int)nums.size(); i++){
            if(nums[i]<num1){
                num1 = nums[i];
            }
            else if(nums[i]>num2){
                num2 = nums[i];
            }
        }
        
        while(num2%num1 != 0){
            int temp = num2%num1;
            num2 = num1;
            num1 = temp;
        }
        
        return num1;
    }
};