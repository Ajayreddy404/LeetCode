class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        
        for(int i = 0; (i+1)<prices.size(); ){
            
            int b_count = 0, buy = prices[i];
            while(b_count==0 && (i+1)<prices.size()){
                if(prices[i+1] > buy){
                    b_count++;
                    i++;
                }
                else{
                    buy = prices[i+1];
                    i++;
                }
            }
            
            int s_count = 0, sell = prices[i];
            while(s_count==0 && (i+1)<prices.size()){
                if(prices[i+1] < sell){
                    s_count++;
                    i++;
                }
                else{
                    sell = prices[i+1];
                    i++;
                }
            }
            
            profit += sell - buy;
        }
        return profit;
    }
};