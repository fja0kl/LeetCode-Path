/**
暴力破解,验证
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j;
        // check every row and column
        for(i=0; i<9; i++){
            unordered_map<int, int> d_r;
            unordered_map<int, int> d_c;
            for(j=0; j<9; j++){
                if(d_r.find(board[i][j]) != d_r.end())
                    return false;
                if(board[i][j] != '.')
                    d_r[board[i][j]] = 1;
                if(d_c.find(board[j][i]) != d_c.end())
                    return false;
                if(board[j][i] != '.')
                    d_c[board[j][i]] = 1;                
            }
        }
        //check sub-boxes
        for(i=0; i<3; i++) for(j=0; j<3; j++){
            unordered_map<int, int> sub;
            for(int k=3*i; k<3*i+3; k++) for(int t=3*j; t<3*j+3; t++){
                if(sub.find(board[k][t]) != sub.end())
                    return false;
                if(board[k][t] != '.')
                    sub[board[k][t]] = 1;
            }
        }
        return true;
    }
};
