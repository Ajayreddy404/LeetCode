class Solution {
public:
    int countSubstrings(string s) {
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

        int ans = 0;

        for(int i=1; i<n2-1; i++){
            ans += (P[i]+1)/2;
        }
        
        return ans;
    }
};