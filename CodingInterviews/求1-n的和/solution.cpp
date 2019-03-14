class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        // 短路与：实现if判断--终止条件；
        // 递归实现 Sum_Solution(n) = ans + Sum_Solution(n-1)
        (ans > 0) && ((ans += Sum_Solution(n-1))>0);
        return ans;
    }
};
