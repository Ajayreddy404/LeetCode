class Solution {
public:
    int countVowelStrings(int n) {
        int ans = (n+4)*(n+3)*(n+2)*(n+1)/(4*3*2*1);
        return ans;
    }
};