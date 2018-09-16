/**
 * 辅助函数
 * 可以写辅助函数，来把复杂化的处理过程独立出来
 */
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.size()==0 || A.empty())
            return A;
        int rows = A.size();
        for(int i=0;i<rows;i++){
            reverse(A[i]);
            invert(A[i]);
        }
        
        return A;
    }
    void reverse(vector<int>& A){
        int i = 0, j = A.size()-1;
        while(i<j)
            swap(A[i++],A[j--]);
    }
    void invert(vector<int>& A){
        for(int i=0;i<A.size();i++)
            A[i] = int(!A[i]);
    }
};
