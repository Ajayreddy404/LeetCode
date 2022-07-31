class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr(numRows);
        for(int n=0; n<numRows; n++){
            arr[n].resize(n+1);
            for(int r=0; r<=n; r++){
                if(r==0 || r==n){
                    arr[n][r] = 1;
                }else{
                    arr[n][r] = arr[n-1][r-1]+arr[n-1][r];
                }
            }
        }
        return arr;
    }
};