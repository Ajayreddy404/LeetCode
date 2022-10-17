class Solution {
public:
    string longestPalindrome(string s) {
        // form the modified string
        string T = "$#";
        for(char c: s){
            T += c;
            T += '#';
        }T += '@';
        int n2 = T.length();

        // initialize the pal len array (P) with all 0s
        int P[n2];
        memset(P,0,sizeof(P));

        int C = 0, R = 0;
        for(int i=0; i<n2-1; i++){
            int mirr = 2*C - i;
            if(i<R){
                P[i] = min(R-i, P[mirr]);
            }

            int right = i + (P[i]+1);
            int left = i - (P[i]+1);
            while(right<n2 && left>=0 && T[right]==T[left]){
                P[i]++;
                right++;
                left--;
            }

            if(P[i]+i > R){
                R = P[i] + i;
                C = i;
            }
        }

        int j=0, maxlen = 0;
        for(int i=0; i<n2; i++){
            int x = P[i];
            if(x>maxlen){
                maxlen = x;
                j = i;
            }
        }

        string ans = "";

        int st = j+1 - maxlen;
        int en = j-1 + maxlen;
        while(st<=en){
            ans += T[st];
            st+=2;
        }
        
        return ans;
    }
};