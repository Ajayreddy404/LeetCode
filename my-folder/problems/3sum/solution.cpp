class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        int n = nums.size();

        for(int i=0; i<n; i++){
            int j=i+1, k = n-1;
            while(j<k){
                int csum = nums[i]+nums[j]+nums[k];
                if(csum>0){
                    k--;
                }else if(csum<0){
                    j++;
                }else if(csum==0){
                    // cout<<i<<" "<<j<<" "<<k<<endl;
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int j1 = j, k1 = k;
                    // removing duplicates as 2nd and 3rd element
                    while(j<k && nums[j]==nums[j1])  j++;
                    while(j<k && nums[k]==nums[k1])  k--;
                }
                
            }

            // removing duplicated at 1st element
            while(i+1<n && nums[i]==nums[i+1])  i++;
        }
        return ans;
    }
};
