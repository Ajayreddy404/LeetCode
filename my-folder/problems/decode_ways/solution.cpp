class Solution {
public:
    int n;
    int dp[101];

    int rec(int level, string& s){
        if(level==n)    return 1;
        if(s[level]=='0')   return -1e9;
        if(dp[level]!=-1)   return dp[level];
        // transition logic
        int ans = 0;
        int a1 = 0, a2 = 0;
        if(s[level]=='1'){
            if(level+1<n && s[level+1]=='0')  ans = rec(level+2,s);
            else{
                a1 = rec(level+1,s);
                if(level+1<n)   a2 = rec(level+2,s);
                if(a1>=0)    ans += a1;
                if(a2>=0)    ans += a2;
            }
        }else if(s[level]=='2'){
            if(level+1<n && s[level+1]=='0')  ans = rec(level+2,s);
            else if(level+1<n && s[level+1]<='6'){
                a1 = rec(level+1,s);
                a2 = rec(level+2,s);
                if(a1>=0)    ans += a1;
                if(a2>=0)    ans += a2;
            }else    ans = rec(level+1,s);
        }else{
            ans = rec(level+1,s);
        }

        return dp[level] = ans;
    }

    int numDecodings(string s) {
        n = s.length();
        // cout<<n<<endl;
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,s);
        if(ans<0)   ans = 0;
        return ans;
    }
};