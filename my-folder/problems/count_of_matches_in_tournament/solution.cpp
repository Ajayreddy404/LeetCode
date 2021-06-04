class Solution {
public:
    int numberOfMatches(int n) {
        int y = 0;
        if(n<2)
            return 0;
        if(n==2)
            y = 1;
        else if(n%2==0){
            y += n/2 + numberOfMatches(n/2);
            
        }
        else{
            y += (n-1)/2 + numberOfMatches((n+1)/2);
        }
        return y;
    }
};