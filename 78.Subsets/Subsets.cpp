class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        int len = nums.size(), n = pow(2, len);
        
        for(int i = 0; i < n; i++){//�����Ʋ������Ӽ����鳤��Ϊ2��len����
            int idx = i;//��Χ�����Ķ����ƾͱ�ʾһ��������Ӽ�����
            vector<int> temp;
            for(int j=0;j<len; j++){//�ж϶����ƽ�����Ƿ�Ϊ1:���뵱ǰ�Ӽ���
                int cur = idx % 2;
                idx /= 2;
                if(cur != 0)
                    temp.push_back(nums[j]);
            }
            res.push_back(temp);//���뵽�Ӽ�������
        }
        
        return res;
    }
};