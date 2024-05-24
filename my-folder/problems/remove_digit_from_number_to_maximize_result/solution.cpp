#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDigit(string s, char x) {
        int n = s.length();
        int ind = -1;
        for(int i=0; i<n; i++){
            if(s[i]==x){
                ind = i;
                if(i+1<n && s[i] < s[i+1]){
                    break;
                }
            }
        }
        s.erase(ind,1);
        return s;
    }
};