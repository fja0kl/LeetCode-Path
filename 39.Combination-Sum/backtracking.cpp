/**
backtracking:尝试选择,找到答案后,回退;重新查找答案.
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        backtrack(result, temp, candidates, target, 0);
        
        return result;
    }
private:
    void backtrack(vector<vector<int>>& all, vector<int>& temp, vector<int>& nums, int remain, int start){
        if(remain < 0) return;
        else if(remain == 0) all.push_back(temp);
        else{
            for(int i=start; i<nums.size(); i++){
                temp.push_back(nums[i]);
                backtrack(all, temp, nums, remain-nums[i], i);
                temp.pop_back();
            }
        }
    }
};
