class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, f = -1, l = -1;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                cnt++;
                if(f==-1)    f = i;
                l = i;
            }
            
        }
        if(cnt==0)  return 0;
        if(cnt==1)  return 1;
        // cout<<f<<" "<<l<<" "<<cnt<<endl;
        
        long long ans = 1, ways = 1;
        for(int i=f; i<=l; i++){
            if(nums[i]==0){
                ways++;
            }else{
                ans = (ans*ways)%mod;
                ways = 1;
            }
        }
        return (int)ans;
    }
};