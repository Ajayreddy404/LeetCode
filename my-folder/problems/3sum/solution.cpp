class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        set<vector<int>> ans;
        for(int i=0; i<n; i++){
            // while(i+1<n && arr[i]==arr[i+1])  i++;
            for(int j=i+1; j<n-1; j++){
                // while(j-1>i+1 && arr[j]==arr[j-1])  j--;
                int num = -(arr[i]+arr[j]);
                // cout<<arr[i]<<" "<<arr[j]<<endl;
                auto it = lower_bound(arr.begin()+j+1, arr.end(), num);
                // cout<<*it<<endl;
                if(it!=arr.end() && num == *it){
                    // vector<int> vec = {arr[i],arr[j],*it};
                    ans.insert({arr[i],arr[j],*it});
                }
            }
        }
        vector<vector<int>> vec;
        for(auto it: ans){
            vec.push_back(it);
        }
        return vec;
    }
};