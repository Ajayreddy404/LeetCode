class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
        int n = piles.size();
        int l = 0, r = n-1, pa = 0, pb = 0;
        while(l<r){
            // alice pick
            int p1 = piles[l], p2 = piles[r];
            if(p1>=p2){
                pa += p1;
                l++;
                p1 = piles[l];
            }
            else{
                pa += p2;
                r--;
                p2 = piles[r];
            }
            
            // bob pick
            if(p1>=p2){
                pb += p1;
                l++;
            }
            else{
                pb += p2;
                r--;
            }
        }
        
        if(pa>pb){
            return true;
        }
        else{
            return false;
        }
    }
};