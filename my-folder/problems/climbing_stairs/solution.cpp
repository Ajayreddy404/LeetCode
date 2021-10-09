class Solution {
public:
    int climbStairs(int n) {
        int num1 = 1, num2 = 2;
        if(n==1){
            return num1;
        }
        for(int i=3; i<=n; i++){
            int temp = num1 + num2;
            num1 = num2;
            num2 = temp;
        }
        return num2;
    }
};