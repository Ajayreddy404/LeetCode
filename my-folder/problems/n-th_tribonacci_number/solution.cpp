class Solution {
public:
    int tribonacci(int n) {
        int num0 = 0, num1 = 1, num2 = 1;
        if(n==0){
            return num0;
        }
        
        for(int i=3; i<=n; i++){
            int temp = num0 + num1 + num2;
            num0 = num1;
            num1 = num2;
            num2 = temp;
        }
        return num2;
    }
};