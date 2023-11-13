class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size();

        // noting indices and elements in a seperate vector
        vector<pair<int,int>> nums;
        for(int i=0; i<n; i++){
            nums.push_back(make_pair(num[i],i));
        }

        // sorting according to the first element
        sort(nums.begin(),nums.end());

        // finding the pair using two pointer approach
        for(int i=0, j=n-1; i<j; ){
            // cout<<i<<j<<nums[i].first<<nums[j].first<<endl;
            if(nums[i].first+nums[j].first==target){
                cout<<nums[i].first<<" "<<nums[j].first<<endl;
                return {nums[i].second,nums[j].second};
            }else if(nums[i].first+nums[j].first>target){
                // cout<<"here"<<endl;
                j--;
            }else{
                i++;
            }
        }
        return {1,1};
    }
};