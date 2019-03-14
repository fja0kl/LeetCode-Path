class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res;
        int size = A.size();
        if (size == 0) return res;
        res.push_back(1);
        // 计算左半部分
        for (int i=0; i<size-1; i++)
            res.push_back(res.back()*A[i]);
        // 计算右半部分
        int temp = 1;
        for (int j=size-1; j>=0; j--){
            res[j] *= temp;
            temp *= A[j];
        }
        return res;
    }
};
