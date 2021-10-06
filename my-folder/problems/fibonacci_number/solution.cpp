class Solution {
public:
    int fib(int n) {
        /*
        //imperative dp approach
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        
        int num1 = 0, num2 = 1;
        for(int i=2; i<=n; i++){
            num1 = num1 + num2;
            int temp = num2;
            num2 = num1;
            num1 = temp;
        }
        return num2;
        */
        //Binets formula
        
        double t = (sqrt(5)+1)/2;
        return round(pow(t,n)/sqrt(5));

        
    }
};