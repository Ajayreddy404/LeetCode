class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        if(n==1)    return arr[0];
        bool zero = false;
        int max_len = -10;
        for(int j=0; j<n; j++){
            int f0 = j-1, s0 = n;
            for(int i=j; i<n; i++){
                if(arr[i]==0){
                    zero = true;
                    s0 = i;
                    break;
                }
            }j = s0;
            if(s0-f0==1)    continue;
            // cout<<f0<<" "<<s0<<endl;
            int fnp = 1, lnp = 1, nc = 0, cur_prod=1;
            for(int i=f0+1; i<s0; i++){
                fnp*=arr[i];
                if(arr[i]<0)    break;
            }
            for(int i=s0-1; i>f0; i--){
                lnp*=arr[i];
                if(arr[i]<0)    break;
            }
            for(int i=f0+1; i<s0; i++){
                if(arr[i]<0)    nc++;
                cur_prod *= arr[i];
            }

            if(nc%2==1 && s0-f0>2){
                cur_prod = max(cur_prod/fnp, cur_prod/lnp);
            }
            // cout<<fnp<<" "<<lnp<<" "<<cur_prod<<endl;
            max_len = max(cur_prod,max_len);
        }
        if(zero && max_len<0)   return 0;
        return max_len;
        
    }
};