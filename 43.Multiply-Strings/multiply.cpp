/**
* 模拟真实乘法计算过程
**/
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string ans(m + n, '0');
        // the real multiplication
        for(int i = m-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                // 单个数字计算：考虑之前的进位
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i+j+1] - '0');
                //低位计算结束
                ans[i+j+1] = sum % 10 + '0';
                //保存进位
                ans[i+j] += sum / 10;
            }
        }
        //return the final result: filter the '0'
        for(int i=0; i< m+n; ++i){
            if(ans[i] != '0')
                return ans.substr(i);
        }
        
        return "0";
    }
};
