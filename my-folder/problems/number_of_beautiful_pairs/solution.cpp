class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            int cnt = 1, temp = nums[i];
            while(temp){
                temp/=10;
                cnt*=10;
            }cnt/=10;
            int a = nums[i]/cnt;
            for(int j=i+1; j<n; j++){
                int b = nums[j]%10;
                // cout<<nums[i]<<" "<<nums[j]<<" "<<a<<" "<<b<<" "<<cnt<<endl;
                if(__gcd(a,b)==1)   ans++;
            }
        }
        return ans;
    }
};