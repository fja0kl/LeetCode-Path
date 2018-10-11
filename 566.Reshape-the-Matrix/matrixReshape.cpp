class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int oriRows = nums.size();
        int oriCols = nums[0].size();
        
        if (oriRows*oriCols != r*c)
            return nums;
        
        vector<int> all;
        for(int i=0;i<oriRows;i++){
            for(int j=0;j<oriCols;j++)
                all.push_back(nums[i][j]);
        }
        vector<vector<int>> res(r,vector<int>(c));
        
        int idx = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                res[i][j] = all[idx++];
        }
        
        return res;
    }
};
