class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, used(nums.size(), 0);
        
        sort(nums.begin(), nums.end());
        recursion(nums, 0, used, out, res);
        
        return res;
    }
private:
    void recursion(vector<int>& nums, int level, vector<int>& used, vector<int>& out, vector<vector<int>>& res){
        if(level >= nums.size()){
            res.push_back(out);
            return;
        }
        //每次都从第一个数开始
        for(int i=0; i<nums.size(); i++){
            //如果使用过，跳过
            if(used[i] == 1) continue;
            //如果和前一个处理后(used数值重置为0)的数相等，跳过
            if(i>0 && nums[i]==nums[i-1] && used[i-1] == 0) continue;
            
            used[i] = 1;
            out.push_back(nums[i]);
            recursion(nums, level+1, used, out, res);
            out.pop_back();
            used[i] = 0;
        }
    }
};
