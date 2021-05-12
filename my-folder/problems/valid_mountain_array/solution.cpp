class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len_arr = arr.size();
        if(len_arr < 3)
            return false;
        
        int temp = arr[0], count = 0;
        
        for(int i=1; i<len_arr; i++){
            
            if(arr[i]>temp && count==0)
                temp = arr[i];
            
            else if(arr[i]<temp){
                temp = arr[i];
                count++;
            }
            
            else
                return false;
        }
        
        if(count==0 || count == len_arr-1)
            return false;
        else
            return true;
    }
};