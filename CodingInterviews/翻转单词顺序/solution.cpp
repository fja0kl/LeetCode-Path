class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        int length = str.size();
        int front = 0, back = 0;//用来记录单词起始位置
        while (front < length){
            while (front < length && str[front] == ' ') front++;
            back = front;
            while (back < length && str[back] != ' ') back++;
            //翻转单词
            reverse(str.begin()+front, str.begin()+back);
            front = back;
        }
        return str;
    }
    
};
