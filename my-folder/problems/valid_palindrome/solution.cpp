class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = "";
        int n = s.length();
        for(int i=0; i<n; i++){
            if(isalpha(s[i])){
                s2 += tolower(s[i]);
            }else if(isdigit(s[i])){
                s2 += s[i];
            }
        }
        // cout<<s2<<endl;

        n = s2.length();
        int i=0,j=n-1;
        while(i<j){
            if(s2[i]!=s2[j])    return false;
            i++; j--;
        }
        return true;
    }
};