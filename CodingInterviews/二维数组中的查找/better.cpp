class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size(), n = array[0].size();
        int i, j;
        for (i=m-1,j=0; i>=0 && j<n;){
            if (array[i][j] == target) return true;
            else if (array[i][j] < target){
                j++;
            } else {
                i--;
            }
        }
        return false;
    }
};
