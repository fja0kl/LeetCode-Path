/**
 * 位运算
 * 当n大于0时，如果n是2的幂，那么
 * n和(n-1)做与运算，应该为0；
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
	    if(n <= 0) return false;

	    return (n&(n-1)) == 0;
    }
};
