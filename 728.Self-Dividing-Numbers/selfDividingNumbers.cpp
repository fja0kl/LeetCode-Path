/**
 * 辅助函数
 */
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i=left;i<=right;i++)
            if (isDividingNumbers(i))
                result.push_back(i);
        
        return result;
    }
    
    bool isDividingNumbers(int n){
        int n_orig = n;
        while(n>0){
            int digit = n % 10;
            if(!digit || n_orig % digit != 0)
                return false;
            n = n / 10;
        }
        return true;
    }
};
