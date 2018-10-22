/**
 * end从前到后；
 * start从后到前；
 *
 *
 *
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), start = -1, end = -2;
        int mn = nums[n - 1], mx = nums[0];
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n - 1 - i]);
            if (mx > nums[i]) end = i;//逆序
            if (mn < nums[n - 1 - i]) start = n - 1 - i;//逆序
        }
        return end - start + 1;
    }
};
