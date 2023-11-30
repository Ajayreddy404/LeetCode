class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int mp = -1e9, cp = 1, cnt = 0, n = arr.size();

        for(int i=0; i<n; i++){
            if(arr[i]==0){
                cp = 1; continue;
            }else{
                cp *= arr[i];
                mp = max(cp, mp);
            }
        }
        
        cp = 1;

        for(int i=n-1; i>=0; i--){
            if(arr[i]==0){
                cp = 1;
                cnt++;
                continue;
            }else{
                cp *= arr[i];
                mp = max(cp, mp);
            }
        }

        if(mp<0 && cnt>0)   mp = 0;

        return mp;
    }
};