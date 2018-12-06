/**
题:一定有一个解.
遍历求和.O(n).

有序数组;同时可能出现相同元素,hash就不行了[unordered_map]
**/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l < r){
            if(numbers[l] + numbers[r] == target)
                break;
            else if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        return vector<int>{l+1,r+1};
    }
};
