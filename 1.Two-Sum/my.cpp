/**
问题只有一个解.

naive: 遍历数组,查看所有可能的情况,符号要求退出.

O(N*N)

**/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                if (nums[i]+nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
	return result;
    }
};
