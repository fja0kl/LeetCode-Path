/**
* 顺时针翻转：等价于数组先对角线翻转，然后再水平翻转。
将顺时针翻转转变成两步，依次进行，操作更方便，易理解。
**/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        
        int m = matrix.size(), n = matrix[0].size();
        // first: cross line
        for (int i=0; i<m; ++i) for (int j=i; j<n; ++j){
            swap(matrix[i][j], matrix[j][i]);
        }
        // second: rotate horizenly
        for (int i=0; i<m; i++) for(int j=0; j<n/2; j++){
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
        return;
    }
};
