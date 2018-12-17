/**
设置numRows个数组,按照顺序依次添加到对应数组中;同时设置步长,用来修改对应的行号:
row == 0: step=1(依次往下,row++);row == numRows-1: step=-1(到最后一行,依次往上,row--行号递减)
row += step;

最后将各行结果依次添加到新字符串中.

将各行结果存储在对应字符串中,不用计算转换后的下标,然后拼接最终结果了.

pros & cons: 容易理解; 浪费存储空间
**/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;
        int len = s.size();
        string* str = new string[numRows];
        int row = 0, step = 1;
        for(int i=0;i<len;i++){
            str[row].push_back(s[i]);
            if(row == 0) step = 1;
            else if(row == numRows-1) step = -1;
            row += step;
        }
        string res;
        for(int i=0;i<numRows;i++)
            res.append(str[i]);
        delete[] str;
        
        return res;
    }
};
