/**
* 贪心：如果能到达最后一层，那么每一层都能到达。
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, reach = 0;
        for (i=0; i<nums.size() && i<=reach; i++)
            reach = max(reach, nums[i]+i);
        return i == nums.size();
    }
};
