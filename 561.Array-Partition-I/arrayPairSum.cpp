/**
 * 推理发现，当对数组排序后，前后依次结对，最终min的和最大
 * 所以：
 * 1. 排序；
 * 2. 取pair的第一个，加和；得到最终结果。
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result = 0;
        for(int i=0;i<nums.size();i+=2){
            result += nums[i];
        }
        return result;
    }
};
