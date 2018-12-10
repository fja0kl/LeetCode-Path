/**
翻转字符串,同时保持单词的有效性:
1. 翻转单个字符;
2. 翻转整个句子.
或者是2-1.

其他:保持空格的正确性:
- 单个空格--单词之间用1个空格连接;
- 句首,句末没有空格;
**/
class Solution {
public:
    void reverseWords(string &s) {
        int i=0, j=0;
        int l=0;
        int wordCnt = 0, len = s.size();
        while(true){
            //过滤空格
            while(i<len && s[i]==' ') i++;//i用来遍历原字符串
            //字符串末尾,退出
            if(i == len) break;
            //不是第一个单词,用单词之间空格连接
            if(wordCnt) s[j++] = ' ';//j新字符串
            //寻找每个单词的范围
            l = j;//记录新字符串的起始位置
            while(i<len && s[i] != ' ') s[j++] = s[i++];
            //对调整后的新字符串翻转
            reverseword(s,l, j-1);
            // reverse(s.begin()+l, s.begin()+j);
            wordCnt++;//
        }
        //调整字符串长度,删除多余的空格[都在字符串最后]
        s.resize(j);
        //翻转整个字符串
        reverseword(s, 0, j-1);
        // reverse(s.begin(), s.end());
    }
private:
    void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        } 
    }
};
