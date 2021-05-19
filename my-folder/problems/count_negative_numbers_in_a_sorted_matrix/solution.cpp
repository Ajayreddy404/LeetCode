class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        int n0 = n;
        for(int i=0; i<m; i++){
            int start = 0, end = n0-1, mid;
            while(start <= end){
                mid = (start + end)/2;
                if(grid[i][mid] >= 0)
                    start = mid+1;
                else
                    end = mid - 1;
            }
            if(grid[i][mid]>=0)
                count += n-1-mid;
            else
                count += n-mid;
            n0 = mid+1;
        }
        return count;
    }
};