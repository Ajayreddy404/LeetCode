class Solution {
public:
    vector<int> path;
    int n;
    
    void dfs(int node, vector<vector<int>>& ans, vector<vector<int>>& graph){
        path.push_back(node);
        if(node==n-1){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        if(graph[node].size()==0){
            path.pop_back();
            return;
        }
        else{
            for(auto x: graph[node]){
                dfs(x,ans,graph);
            }
        }
        path.pop_back();
        return;
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        n = graph.size();
        
        dfs(0,ans,graph);
        return ans;
    }
};