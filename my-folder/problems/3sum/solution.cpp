class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // for(auto x: nums){
        //     cout<<x<<" ";
        // }cout<<endl;
        set<vector<int>> st;
        vector<vector<int>> vec;

        for(int i=0; i<n; i++){
            // int i1 = i+1;
            // cout<<i<<endl;
            // while(i1<n && nums[i1]==nums[i]){
            //     i1++; i++;
            // }
            
            int j = i+1, k = n-1;
            // cout<<i<<j<<k<<endl;
            
            while(j<k){
                // cout<<i<<j<<k<<endl;
                int csum = nums[i]+nums[j]+nums[k];
                if(csum==0){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++; k--;
                }else if(csum>0){
                    // int k1 = k;
                    // while(k>j && nums[k1]==nums[k])    
                    k--;
                }else{
                    // int j1 = j;
                    // while(j<k && nums[j1]==nums[j])    
                    j++;
                }
            }
            
        }

        for(auto v: st){
            vec.push_back(v);
        }
        return vec;
    }
};