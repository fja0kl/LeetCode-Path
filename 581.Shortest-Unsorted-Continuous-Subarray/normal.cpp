/**
 * 多了个限制条件
 *
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> b(nums);
        sort(b.begin(),b.end());
        int n = nums.size(), i = 0, j = n-1;
        while(i < n && nums[i] == b[i]) i++;
        while(j > i && nums[j] == b[j]) j--;//减少比较次数，同时避免了j<i的情况
        
        return j-i+1;
        
    }
};
