class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<findNums.size();i++){
            int j=0,k=0;
            for(;j<nums.size();j++)//子集元素在全集中找到位置
                if(nums[j] == findNums[i]) 
                    break;
            for(k=j+1;k<nums.size();k++)
                if(nums[k]>findNums[i]){
                    result.push_back(nums[k]);
                    break;
                }
            if(k==nums.size())
                result.push_back(-1);
        }
        return result;
    }
};
