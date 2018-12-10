/**
必须是left是字母,right是字母时才判断;

也可以包括数字:所以是isalnum函数,而不仅仅是isalpha函数
(s[left]+32 - 'a') % 32: 字母大小写格式转换.
+32: ascii码中对应两个字母之间相差32;
-'a': 得到转换后距离一个字母的大小位置;
%32: 保证无论是大写+32 和 小写+32,取余结果都相同.

eg: 'A'=65, 'a'=97;
('A'+32-'a')%32=(65+32-97)%32 = 0;
('a'+32-'a')%32=(97+32-97)%32 = 0;
相等.
**/
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            //过滤掉不是字母的字符
            if(!isalnum(s[left])) left++;
            else if(!isalnum(s[right])) right--;
            //找到两个都是字母的字符判断是否相等:注意转换成小写
            else if((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32)
                return false;
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};
