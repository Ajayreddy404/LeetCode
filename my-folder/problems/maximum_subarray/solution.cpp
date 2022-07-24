class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int msum = -1e5, csum = 0, mnum = -1e5;
        bool flag = false;
        for(int i=0; i<n; i++){
            mnum = max(mnum, arr[i]);
            if(arr[i]>=0)    flag = true;
            csum += arr[i];
            if(csum<0)  csum = 0;
            msum = max(csum,msum);
        }
        
        if(!flag)   return mnum;
        return msum;
    }
};