class Solution {
public:
    int n;
//     bool dp[100100];
    
//     int rec(int level, vector<int>& arr){
//         if(level>=n-1)  return dp[level] = true;
        
//         if(dp[level])   return true;
        
//         bool ans = false;
//         for(int i=arr[level]; i>0; i--){
//             if(rec(level+i,arr)){
//                 ans = true;
//                 break;
//             }
//         }
        
//         return dp[level] = ans;
//     }
    
    bool canJump(vector<int>& arr) {
        n = arr.size();
        int ans = arr[0];
        for(int i=1; i<n; i++){
            if(ans < i) break;
            ans = max(ans,i+arr[i]);
        }
        return (ans>=n-1)? true : false;
    }
};