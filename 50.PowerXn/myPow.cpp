/**
* 二分法: x^n = x^(n/2) * x^(n/2) * x^(n % 2)
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1.0/helper(x,-n);
        return helper(x, n);
    }
private:
    double helper(double x, int n){
        if(n == 0) return 1.0;
        double v = helper(x, int(n/2));
        if(n % 2 == 0)
            return v*v;
        return v*v*x;
    }
};
