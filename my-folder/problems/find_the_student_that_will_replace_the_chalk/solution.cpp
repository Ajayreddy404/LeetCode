class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long tsum = 0;
        for(auto x: chalk){
            tsum += x;
        }

        k = k%tsum;
        int ans = 0;
        tsum =  0;
        for(int i=0; i<chalk.size(); i++){
            tsum += chalk[i];
            if(k/tsum==0){
                ans = i;
                break;
            }
        }
        return ans;
    

    }
};