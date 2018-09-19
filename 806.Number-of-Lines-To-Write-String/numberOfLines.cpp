/**
 * 缓冲区思想：类比写word文档
 */
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> result;
        int buffer = 100, line = 1;
        for(int i=0;i<S.length();i++){//循环字符串
            int width = widths[S[i]-'a'];//获取当前字符的长度
            if(buffer >= width){//缓冲区大小是否能容下当前字符？
                buffer -= width;
            }
            else{//放不下，另起一行;重新计算缓冲区
                line++;
                buffer = 100 - width;
            }
        }
        result.push_back(line);
        result.push_back(100-buffer);
        
        return result;
    }
};
