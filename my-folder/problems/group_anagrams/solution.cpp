class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        // sort each string and store the unique values in a map along with its indices
        int n = arr.size();
        // cout<<n<<endl;
        string s = "";
        unordered_map<string,vector<int>> mp;
        for(int i=0; i<n; i++){
            s = arr[i];
            sort(s.begin(),s.end());
            // cout<<s<<endl;
            if(mp.find(s)==mp.end()){
                mp[s] = {i};
            }else{
                mp[s].push_back(i);
            }
        }

        vector<vector<string>> ans;
        for(auto v: mp){
            vector<string> temp;
            for(auto i: v.second){
                temp.push_back(arr[i]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};