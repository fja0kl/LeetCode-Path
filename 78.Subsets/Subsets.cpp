class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        int len = nums.size(), n = pow(2, len);
        
        for(int i = 0; i < n; i++){//二进制操作：子集数组长度为2的len次幂
            int idx = i;//范围内数的二进制就表示一个合理的子集序列
            vector<int> temp;
            for(int j=0;j<len; j++){//判断二进制结果，是否为1:加入当前子集中
                int cur = idx % 2;
                idx /= 2;
                if(cur != 0)
                    temp.push_back(nums[j]);
            }
            res.push_back(temp);//加入到子集数组里
        }
        
        return res;
    }
};