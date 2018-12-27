/**
解法:和3Sum类似,不过是返回离目标值最近的3个数的和.

abs(num):求绝对值

sort(a.begin(),a.end());排序算法
**/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = nums.size()-1;
            while(l < r){
                int curSum = nums[i] + nums[l] + nums[r];
                if(curSum == target) return target;
                if(abs(target - curSum) < abs(target- closest))
                    closest = curSum;
                if(curSum > target) r--;
                else{
                    l++;
                }
            }
        }
        return closest;
    }
};

