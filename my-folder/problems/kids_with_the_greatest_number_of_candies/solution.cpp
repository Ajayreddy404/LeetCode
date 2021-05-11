class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> check(candies.size());
        int max_val = 0;
        
        for(auto val : candies){
            if(val > max_val)
                max_val = val;
        }
        
        for(int i = 0; i<n; i++){
            if(candies[i]+extraCandies >= max_val)
                check[i] = true;
            else
                check[i] = false;
        }
        
        return check;
    }
};