class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.empty()) return {};
        int start = 0, rows = matrix.size(), cols = matrix[0].size();
        vector<int> result;
        while (rows > 2*start && cols > 2*start){
            printMatrixInCycle(matrix, rows, cols, start, result);
            start++;
        }
        return result;
    }
    void printMatrixInCycle(vector<vector<int>> matrix, int rows, int cols,
                                  int start, vector<int>& result){
        int endX = cols - 1 - start;
        int endY = rows - 1 - start;
        // 从左到右打印一行
        for (int i=start; i<=endX; i++)
            result.push_back(matrix[start][i]);
        // 从上到下打印一列:条件是存在多行
        if (start < endY){
            for (int i=start+1; i<=endY; i++)
                result.push_back(matrix[i][endX]);
        }
        // 从右向左打印一行: 多行 而且 多列
        if (start < endY && start < endX){
            for (int i=endX-1; i>=start; i--)
                result.push_back(matrix[endY][i]);
        }
        // 从下到上打印一列： 至少有3行(endY-start>=2)，而且有多列
        if (endY-start >= 2 && start < endX){
            for (int i=endY-1; i>=start+1; i--)
                result.push_back(matrix[i][start]);
        }
        
    }
};
