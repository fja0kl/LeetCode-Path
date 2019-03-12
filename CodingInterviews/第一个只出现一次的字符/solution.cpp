
class Solution {
public:
    bool b_InvalidInputs = false;//记录-1是无效输入还是没有
    int FirstNotRepeatingChar(string str) {
        if (str.empty()){
            b_InvalidInputs = true;
            return -1;
        }
        b_InvalidInputs = false;
        const int size = 256;
        int hashTbl[size];
        // hashTable初始化
        for (int i=0; i<size; i++)
            hashTbl[i] = 0;
        // hashTable统计
        int index = 0;
        while (index != str.size())
            hashTbl[str[index++]]++;
        // 遍历，找到第一个出现一次的字符
        index = 0;
        while (index != str.size()){
            if (hashTbl[str[index]] == 1)
                return index;
            index++;
        }
        return -1;
    }
};
