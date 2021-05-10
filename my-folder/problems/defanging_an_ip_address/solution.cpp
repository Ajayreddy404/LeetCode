class Solution {
public:
    string defangIPaddr(string address) {
        string df_address = "";
        for(auto &c : address){
            if(c == '.')
                df_address += "[.]";
            else
                df_address += c;
        }
        return df_address;
    }
};