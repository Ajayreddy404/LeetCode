class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n-1;
        int mw = 0;
        while(i<j){
            int h = min(arr[i],arr[j]);
            // cout<<h<<endl;
            mw = max(mw, h*(j-i));
            
            while(i<j && arr[i]<=h)    i++;
            // cout<<"h1"<<endl;
            while(i<j && arr[j]<=h)    j--;
        }
        return mw;
    }
};