class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        int count = 0, element = vec[0];
        for(int i=1; i<vec.size(); i++){
            if(vec[i] != element){
                element = vec[i];
                count++;
            }
            if(count==2)
                return element;
        }
        return vec[0];
    }
};