class Solution {
public:
    int getLucky(string s, int k) {
        string s1 = "", s2 = "";
        for(int i=0; i<s.length(); i++){
            int temp = s[i]-'a';
            s1 += to_string(temp+1);
        }
        // cout<<s1<<endl;
        while(k--){
            int n = s1.length(), t = 0;
            for(int i=0; i<n; i++){
                t += int(s1[i]-'0');
                // cout<<t<<" ";
            }//cout<<endl;
            s1 = to_string(t);
            // cout<<s1<<endl;
        }
        return stoi(s1);
    }
};