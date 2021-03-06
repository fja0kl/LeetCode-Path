/**
* 减少重复运算，自下而上计算，节省空间，减少栈溢出风险。
*/
class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int fiNMinusOne = 1, fiNMinusTwo = 0, fiNResult = 0;
        for (int i=2; i<=n; i++){
            fiNResult = fiNMinusOne + fiNMinusTwo;
            fiNMinusTwo = fiNMinusOne;
            fiNMinusOne = fiNResult;
        }
        return fiNResult;
    }
};
