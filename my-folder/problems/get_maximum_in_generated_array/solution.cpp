class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        int maxN = 1;
        vector<int> arr(n+1);
        arr[0]=0; arr[1]=1;
        
        for(int i=2; i<=n; i++){
            int i1 = i/2, i2 = (i/2)+1;
            if(i%2==0){
                arr[i]=arr[i1];
            }
            else{
                arr[i]=arr[i1]+arr[i2];
                maxN = max(maxN, arr[i]);
            }
        }
        return maxN;
    }
};