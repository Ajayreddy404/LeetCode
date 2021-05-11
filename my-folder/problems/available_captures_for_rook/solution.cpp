class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        
        int n = board[0].size(), x, y;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='R'){
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        
        int count = 0;
        for(int i=x+1, j=y; i<n && board[i][j]!='B'; i++){ //pawn check towards right
            if(board[i][j]=='p'){
                count++;
                break;
            }
        }
        for(int i=x-1, j=y; i>=0 && board[i][j]!='B'; i--){ //pawn check towards left
            if(board[i][j]=='p'){
                count++;
                break;
            }
        }
        for(int i=x, j=y+1; j<n && board[i][j]!='B'; j++){ //pawn check towards down
            if(board[i][j]=='p'){
                count++;
                break;
            }
        }
        for(int i=x, j=y-1; j>=0 && board[i][j]!='B'; j--){  //pawn check towards up
            if(board[i][j]=='p'){
                count++;
                break;
            }
        }
        
        return count;
    }
};