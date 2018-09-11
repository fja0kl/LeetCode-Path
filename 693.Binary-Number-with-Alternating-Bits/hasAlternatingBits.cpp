class Solution {
public:
    bool hasAlternatingBits(int n) {
        //交替性 n右移一位与n相加结果应该全是1，在加1进位；在和全1与操作；如果为0，true
        return ((n+(n>>1)+1) & (n+(n>>1))) == 0;
    }
};
