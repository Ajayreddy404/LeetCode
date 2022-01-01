class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> Q;
        int len = 0, maxlen = 0;
        for(int i=0; i<nums.size()&&k==0; i++){
            if(nums[i]){
                len++;
            }
            else{
                len = 0;
            }
            maxlen = max(maxlen,len);
        }
        
        for(int i=0; i<nums.size() && k; i++){
            if(nums[i]){
                len++;
            }
            else{
                if(Q.size()<k){
                    Q.push(i);
                    len++;
                }
                else{
                    int l = Q.front();
                    Q.pop();
                    Q.push(i);
                    len = i - l;
                }
            }
            maxlen = max(maxlen,len);
        }
        return maxlen;
    }
};