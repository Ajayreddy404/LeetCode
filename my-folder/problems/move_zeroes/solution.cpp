class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        //removing zeroes and cunting their number
        for(auto itr = nums.begin(); itr != nums.end(); itr++)
        {
            if(*itr == 0){
                nums.erase(itr);
                count++;
                itr--;
            }
        }
        
        //adding zeros at the end
        for(; count>0; count--)
        {
            nums.push_back(0);
        }
    }
};