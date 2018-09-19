/**
 * 时间复杂度O(N**2)
 */
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int top = 0,front = 0, side = 0;
        for(int i=0;i<grid.size();i++){
            int rowMax = 0, colMax = 0;
            for(int j=0;j<grid.size();j++){
                if(rowMax < grid[i][j])
                    rowMax = grid[i][j];
                if(colMax < grid[j][i])
                    colMax = grid[j][i];
                if(grid[i][j])
                    top++;
            }
            front += rowMax;
            side += colMax;
        }
        return top+front+side;
    }
};
