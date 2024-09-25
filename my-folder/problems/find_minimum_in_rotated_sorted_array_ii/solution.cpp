class Solution {
public:

    int rec(int i, int j, vector<int>& nums){
        int n = nums.size();

        if(i>j || j<0 || i>=n)    return 1e6;
        if(i==j)    return nums[i];
        if(j-i==1) return min(nums[i], nums[j]);
        if(nums[i]<nums[j])   return nums[i]; // non-rotated

        int mid = (i+j)/2;
        int ans = nums[mid];
        
        // take care of mid-1 >=0
        if(mid>0 && nums[mid-1]>nums[mid]){
            ans =  nums[mid];
        }else if(nums[mid]>nums[i]){
            ans = rec(mid+1,j,nums);
        }else if(nums[mid]<nums[i]){
            ans = rec(i,mid-1,nums);
        }else if(nums[i]==nums[mid]){
            if(nums[mid]==nums[j])    ans = min(rec(i,mid-1,nums), rec(mid+1,j,nums));
            else    ans = rec(mid+1,j,nums);
        }
        
        return ans;
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        if(n==2) return min(nums[0],nums[1]);
        if(nums[0]<nums[n-1])   return nums[0]; // non-rotated

        int i = 0, j = n-1;
        
        int ans = rec(i,j,nums);
        return ans;
    }
};