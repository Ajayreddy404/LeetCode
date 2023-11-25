class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if(n<=1)   return 0;

        int arr1[n], arr2[n];   // arr1[]-> max from right, arr2[]-> min from left
        arr1[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            if(arr[i]>arr1[i+1])    arr1[i] = arr[i];
            else arr1[i] = arr1[i+1];
        }

        arr2[0] = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]<arr2[i-1])    arr2[i] = arr[i];
            else    arr2[i] = arr2[i-1];
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, arr1[i]-arr2[i]);
        }
        return ans;

        return ans;
    }
};


// if(flag == 0){
//     if((i==0 && arr[i]<arr[i+1]) || (i<n-1 && arr[i]<arr[i+1] && arr[i]<arr[i-1])){
//         bp = arr[i];
//         flag = !flag;
//     }
// }else{
//     if((i==n-1 && arr[i]>arr[i-1]) || (arr[i]>arr[i-1] && arr[i]>arr[i+1])){
//         ans += arr[i] - bp;
//         cout<<bp<<" "<<arr[i]<<endl;
//         flag = !flag;
//     }
// }