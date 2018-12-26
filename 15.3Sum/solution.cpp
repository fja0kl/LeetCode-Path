/**
3Sum固定一个值,退化成2Sum.
充分利用有序数组的特性.

双指针:一个指头l,一个指尾r;
if nums[l]+nums[r] > target: r--;
因为有序数组,头和尾两个数之和大于target,由于尾是较大值,此时两个数之和都大于target,那么只能移动右指针,让右边元素变小一点,这样才有可能两个元素之和等于target;
if nums[l]+nums[r] < target: l++;
两个元素之和过小,让左指针变大,才有可能两个元素之和等于target

这个问题的关键在于,remove duplicates,没有重复解!

由于我们是固定一个,然后做2Sum,重复情况有:
- 如果固定的这个元素在上次迭代过程中已经固定过了,那么就没有必要再进行固定了(因为这个元素和之前的元素相同,如果上次固定时有解,那么这次固定也有解;反之也成立);
- 如果2Sum问题中,找到一次之后,左边界的下一个元素和左边界相同,那么将l++,移动左边界,跳过所有和左边界相同的元素;
- 如果2Sum问题中,找到一次之后,右边界的前一个元素和右边界相同,那么将r--,移动右边界,跳过所有和右边界相同的元素;

Finished!

**/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        //固定一个,退化成2Sum
        for(int i=0;i<nums.size();i++){
            //开头重复
            //跳过相同元素,如果当前固定值和上次固定值相同,可以直接跳过,不用计算
            if((i > 0) && (nums[i] == nums[i-1]))
                continue;
            int left = i+1, right = nums.size()-1;
            //2Sum 寻找两个数之和等于-nums[i]
            while(left < right){
                int s = nums[i]+nums[left]+nums[right];
                if(s< 0)
                    left++;
                else if(s > 0)
                    right--;
                else{
                    //Found!
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //跳过重复解
                    //如果left左边重复
                    while(left+1 < right && nums[left] == nums[left+1]) left++;
                    //如果right右边重复
                    while(right-1 < left && nums[right] == nums[right-1]) right--;
                    //其他情况,此时left,right,i对应元素之和也等于target,却是重复解
                    left++; right--;
                }
            }
        }
        return res;
    }
};
