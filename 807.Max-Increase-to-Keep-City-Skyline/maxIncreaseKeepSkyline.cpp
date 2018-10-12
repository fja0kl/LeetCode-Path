/**
 * 先遍历数组记录每行最大值、每类最大值；
 * 新数组每个元素的值是 当前行最大值和当前列最大值中间的较小值；
 * 再计算increment
 */
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        vector<int> maxRows;
        vector<int> maxCols;
        
        for(int i=0;i<grid.size();i++){
            int maxRow=0, maxCol=0;
            for(int j=0;j<grid[0].size();j++){
                maxRow = max(maxRow, grid[i][j]);
                maxCol = max(maxCol, grid[j][i]);
            }
            maxRows.push_back(maxRow);
            maxCols.push_back(maxCol);
        }
        int increment = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                increment = increment + min(maxRows[i],maxCols[j]) - grid[i][j];
            }
        }
        return increment;
    }
};
