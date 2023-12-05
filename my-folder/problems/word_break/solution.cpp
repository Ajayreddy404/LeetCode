class Solution {
public:
    int n;
    bool dp[301];
    bool saved[301];
    unordered_set<string> st;

    bool rec(int level, string& s){
        if(level==n)    return true;
        if(saved[level])    return dp[level];
        bool ans = false;
        for(int l=1; l<=20; l++){
            string t = s.substr(level,l);
            if(st.find(t)!=st.end() && level+l<=n){
                ans |= rec(level+l,s);
            }
        }
        saved[level] = true;
        return dp[level] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        for(auto t: wordDict){
            st.insert(t);
        }
        return rec(0,s);
    }
};

