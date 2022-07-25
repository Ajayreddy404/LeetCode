class Solution {
public:
    int getMaxLen(vector<int>& arr) {
        int n = arr.size();

        int max_len = 0;
        for(int j=0; j<n; j++){
            int f0 = j-1, s0 = n;
            for(int i=j; i<n; i++){
                if(arr[i]==0){
                    s0 = i;
                    break;
                }
            }j = s0;

            int fnl = 0, lnl = 0, nc = 0, cur_len=0;
            for(int i=f0+1; i<s0; i++){
                fnl++;
                if(arr[i]<0)    break;
            }
            for(int i=s0-1; i>f0; i--){
                lnl++;
                if(arr[i]<0)    break;
            }
            for(int i=f0+1; i<s0; i++){
                if(arr[i]<0)    nc++;
            }

            if(nc%2==0){
                cur_len = s0-f0-1;
            }
            else{
                cur_len = max(s0-f0-1-fnl,s0-f0-1-lnl);
            }

            max_len = max(cur_len,max_len);
        }
        return max_len;
        
    }
};