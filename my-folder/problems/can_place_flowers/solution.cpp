class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int f_cnt = 0;
        if(flowerbed.size()>1){
            for(int i=0; i<flowerbed.size(); i++){
                if(i==0){
                    if(flowerbed[i]==0 && flowerbed[i+1]==0){
                        f_cnt++;
                    }
                    i++;
                }
                else if(i==flowerbed.size()-1){
                    if(flowerbed[i]==0 && flowerbed[i-1]==0)
                        f_cnt++;
                }
                else{
                    if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                        f_cnt++;
                        i++;
                    }
                }
            }
        }
        else{
            if(flowerbed[0]==0)
                f_cnt++;
        }
        
        if(f_cnt < n)
            return false;
        else
            return true;
    }
};