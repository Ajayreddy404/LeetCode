class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        vector<int>::iterator it;
        
        for(auto it1 = nums.begin(); it1 != nums.end(); it1++){
            for(auto it2 = it1+1; it2 != nums.end(); it2++){
                if(*(it1) == *(it2))
                {
                    nums.erase(it2);
                    it2--;
                }
            }
        }
        return nums.size();
    }
};