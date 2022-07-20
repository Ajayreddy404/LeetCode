class Solution {
public:
    int tribonacci(int n) {
        int x=0, y=1, z=1;
        if(n==0)    return 0;
        for(int i=3; i<=n; i++){
            int temp = x+y+z;
            x = y;  y = z;  z = temp;
        }
        return z;
    }
};