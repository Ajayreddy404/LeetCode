class Solution {
public:
    string reverseOnlyLetters(string S) {
        string S2, temp = "";
        S2.resize(S.length());
        S2 = S;
        
        for(int i=0; i<S.length(); i++){
            int num = (int)S[i];
            
            if((num>=65 && num<=90) || (num>=97 && num<=122)){
                temp += S[i];
                S2[i] = ' ';
            }
        }
        
        int len = temp.length(), count = 0;
        for(int i=0; i<=S.length(); i++){
            if((int)S2[i] == 32){
                S2[i] = temp[len-1-count];
                count++;
            }
        }
        
        return S2;
        
    }
};