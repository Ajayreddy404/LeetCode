class Solution {
public:

    bool charseq(char c1, char c2){
        if(c1!='z'){
            if(c1+1==c2)    return true;
            else    return false;
        }else{
            if(c2=='a') return true;
            else return false;
        }
    }
    int findSubstringInWraproundString(string p) {
        // to store the maxlen of a substring that ends at a particular character
        unordered_map<char,int> mp;
        int maxlen = 1;
        int n = p.length();
        for(int i=0; i<p.length(); i++){
            if(mp.find(p[i])==mp.end()){
                mp[p[i]] = maxlen;
            }else{
                mp[p[i]] = max(maxlen,mp[p[i]]);
            }

            if(i+1<n && charseq(p[i],p[i+1])){
                maxlen++;
            }else{
                maxlen = 1;
            }
        }

        int ans = 0;
        for(auto p: mp){
            ans += p.second;
        }
        return ans;
    }
};