int BS(vector<int>& nums, int s, int e, int x){
    while(s<=e){
        int mid = s+(e-s)/2;
        //cout<<"->"<<s<<mid<<e<<endl;
        if(nums[mid]==x){
            return mid;
        }
        else if(nums[mid]>x){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        //cout<<s<<mid<<e<<"<-"<<endl;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //finding the index of the smallest element in the pivoted array
        int e = nums.size()-1, s = 0, ind;

        //corner case if only one element
        if(e==0){
            if(target==nums[e]) return e;
            else return -1;
        }

        // finding the smallest element in the pivoted array
        while(s<=e){
            ind = s + (e-s)/2;
            //cout<<s<<ind<<e<<endl;
            if(s!=ind && nums[ind]>nums[s] && nums[ind]>nums[e]){
                s =  ind+1;
            }
            else if(s==ind){
                if(s<nums.size()-1 && nums[s]>nums[s+1]){
                    ind =  ind+1;
                }
                break;
            }
            else{
                e = ind;
            }
            //cout<<s<<ind<<e<<endl;
        } //now ind is the index of the smallest element in the pivoted array
        //cout<<ind<<endl;

        //finding the index of the target in the array
        int ans = -1, mid = ind;
        if(mid==0){
            ans = BS(nums, 0, nums.size()-1, target);
        }
        else{
            if(target>=nums[mid] && target <= nums.back()){
                ans = BS(nums, mid, nums.size()-1, target);
            }
            else if(target>=nums[0] && target <= nums[mid-1]){
                ans = BS(nums, 0, mid-1, target);
            }
        }

        return ans;

    }
};