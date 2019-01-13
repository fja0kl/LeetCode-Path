/**
* 比当前排列大的下一个排列;
* 大:字典顺序比较
* example: 1 3 7 4 2 1
* output: 1 4 1 2 3 7
* 下一个:排列之间存在一定的顺序,同时保证是字典顺序
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2, j = nums.size()-1;
        // 从后往前先找到第一个违反降序的位置
        while(i>=0 && nums[i] >= nums[i+1]) i--;
        // 非全降序序列
        if(i>=0){
            //在i之后序列中,找到第一个比i大的数
            while(nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        //翻转i之后的序列
        reverse(nums.begin() + i + 1, nums.end());
    }
};
