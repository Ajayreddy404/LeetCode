class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int mod = 1e8;
        int ans = mod;
        
        unordered_map<int,int> ump;
        for(int i=0; i<n; i++){
            if(ump.find(cards[i])==ump.end()){
                ump[cards[i]] = i;
            }else{
                ans = min(ans,i - ump[cards[i]] + 1);
                ump[cards[i]] = i;
            }
        }
        
        if(ans==mod)    return -1;
        return ans;
    }
};