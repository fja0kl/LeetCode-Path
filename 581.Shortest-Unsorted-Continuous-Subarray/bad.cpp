/**
 * 排序
 *
 * 前后指针：注意一种特殊情况，数组已经有序
 *
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> backup(nums);
        sort(backup.begin(),backup.end());
        int a=0,b=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i] != backup[i])
                break;
            else
                a++;
        
        for(int j=nums.size()-1;j>=0;j--)
            if(nums[j] != backup[j])
                break;
            else
                b++;
        
        return (a + b) > nums.size() ? 0 : nums.size()-a-b;
    }
};
