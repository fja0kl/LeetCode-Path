/**
 * 双向队列:
 * 前后指针
 */
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int start = 0, end = n-1;
        vector<int> result(n, 0);
        for(int i=0;i<n;i++){
            if(A.at(i) % 2 ==0)
                result[start++] = A.at(i);
            else
                result[end--] = A.at(i);
        }
        return result;
    }
};
