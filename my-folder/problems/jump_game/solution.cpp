class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        for(int i=0; i<n && i<=curr; i++){
            curr = max(curr, i+nums[i]);
        }
        if(curr>=n-1){
            return true;
        }
        else{
            return false;
        }
    }
};