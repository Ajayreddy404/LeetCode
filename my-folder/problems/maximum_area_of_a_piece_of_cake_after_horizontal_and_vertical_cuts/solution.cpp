class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(),verticalCuts.end());
        
        long max_h=0, max_w=0;
        for(int i=1; i<horizontalCuts.size(); i++){
            if(abs(horizontalCuts[i-1]-horizontalCuts[i]) > max_h)
                max_h = abs(horizontalCuts[i-1]-horizontalCuts[i]);
        }
        for(int j=1; j<verticalCuts.size(); j++){
            if(abs(verticalCuts[j-1]-verticalCuts[j]) > max_w)
                max_w = abs(verticalCuts[j-1]-verticalCuts[j]);
        }
        long long result = max_h*max_w;
        return result%1000000007;
    }
};