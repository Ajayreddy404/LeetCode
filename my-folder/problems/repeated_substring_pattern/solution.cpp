class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // find the kmp array of s
        // find the first max of kmp[i] starting from i=1
        // if this max val + kmp[n] == len(s), then true;
        int n = s.length(), i=0, j=-1;
        int kmp[n+1];
        kmp[0] = -1;

        // kmp algo
        while(i<n){
            while(j!=-1 && s[i]!=s[j]){
                j = kmp[j];
            }
            i++; j++;
            kmp[i] = j;
        }
        // for(auto it:kmp){
        //     cout<<it<<" ";
        // }cout<<endl;

        int k = n-kmp[n];
        
        
        if(kmp[n]==0 || n%k!=0) return false;
        
        return true;
    }
};