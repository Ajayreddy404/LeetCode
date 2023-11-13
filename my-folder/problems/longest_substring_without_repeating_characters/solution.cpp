class Solution {
public:
    map<char,int> mp;

    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0)   return 0;

        int maxlen = 1, len = 1, i = 0, j = 1;
        mp[s[0]] = 1;

        while(i<n && j<n){
            while(mp[s[j-1]]<2 && j<n){
                mp[s[j]]++;
                len++;
                j++;
            }
            maxlen = max(maxlen,(mp[s[j-1]]<2)?len:len-1);
            while(mp[s[j-1]]>1 && i<j){
                mp[s[i]]--;
                i++;
                len--;
            }
        }
        return maxlen;
    }
};