class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        if(ruleKey == "type"){
            for(auto item : items){
                if(item[0] == ruleValue)
                    count++;
            }
        }
        
        else if(ruleKey == "color"){
            for(auto item : items){
                if(item[1] == ruleValue)
                    count++;
            }
        }
        
        else if(ruleKey == "name"){
            for(auto item : items){
                if(item[2] == ruleValue)
                    count++;
            }
        }
        
        return count;
    }
};