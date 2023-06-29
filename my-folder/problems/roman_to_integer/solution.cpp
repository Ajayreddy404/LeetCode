class Solution {
public:
    vector<int> getNum(string &s){
        vector<int> num;
        for(auto c: s){
            if(c=='I')  num.push_back(1);
            else if(c=='V')  num.push_back(5);
            else if(c=='X')  num.push_back(10);
            else if(c=='L')  num.push_back(50);
            else if(c=='C')  num.push_back(100);
            else if(c=='D')  num.push_back(500);
            else if(c=='M')  num.push_back(1000);
        }
        return num;
    }
    int romanToInt(string s) {
        vector<int> num = getNum(s);
        int ans = 0;
        int i;
        for(i=0; i<(int)num.size()-1; i++){
            if(num[i]<num[i+1]){
                ans-=num[i];
            }else{
                ans+=num[i];
            }
        }
        ans += num[i];
        return ans;
    }
};