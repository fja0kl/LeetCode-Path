/**
最朴素的解法:使用了对称性,过滤了一部分;O(N*N);
遍历所有可能的解,求最值.
存在优化空间.
**/
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size()<2)
            return 0;
        int res = 0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                int minH = min(height[i], height[j]);
                int tmp = minH * (j-i);
                res = max(res, tmp);
            }
        }
        return res;
    }
};
