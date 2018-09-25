/**
 * 辅助函数
 * 位运算：和1做位运算，判断末尾是0还是1；
 * 右移---相当于除以2；二进制运算
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0;i<=num;i++)
            res.push_back(helper(i));
        
        return res;
    }
    int helper(int num){
        int cnt = 0;
        while(num){
            if(num & 0x1)
                cnt++;
            num = num >> 1;
        }
        return cnt;
    }
};
