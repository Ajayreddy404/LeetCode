class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0, j=n-1;
        
        while(i!=j){
            int mid = (i+j)/2;
            if(nums[mid]>nums[n-1]){
                i = mid+1;
            }else{
                j = mid;
            }
        }// now i is the index of the min element

        if(i==0 && (target > nums[n-1] || target < nums[0])){
            return -1;
        }else if(i!=0 && (target<nums[i] || target>nums[i-1])){
            return -1;
        }

        int front, back;
        if(target<=nums[n-1]){
            front = i;
            back = n-1;
        }else{
            front = 0;
            back = i-1;
        }
        // cout<<front<<" "<<back<<endl;

        while(front!=back){
            int mid = (front+back)/2;
            if(target<=nums[mid]){
                back = mid;
            }else{
                front = mid+1;
            }
        }
        
        if(nums[front]!=target) return -1;
        return front;

    }
};