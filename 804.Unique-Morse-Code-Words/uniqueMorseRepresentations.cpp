/**
 *
 *
 */

//My Solution: ugly, but finished.




class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.size()==0)
            return 0;
        int numb = 1;
        string mouseCodes[] = {".-","-...","-.-.","-..",".","..-.","--.",
                               "....","..",".---","-.-",".-..","--","-.",
                               "---",".--.","--.-",".-.","...","-","..-",
                               "...-",".--","-..-","-.--","--.."};

        for(int i=0;i<words.size();i++){
            string temp = "";
            for(int j=0;j<words[i].length();j++){
                temp += mouseCodes[words[i][j]-'a'];
            }
            words[i] = temp;
        }
        sort(words.begin(),words.end());
        for(int t=0;t<words.size()-1;t++){
            if(words[t] == words[t+1])
                continue;
            else{
                numb++;
            }
        }

        return numb;
    }
};

// Beautiful Solution
// 利用STL的unordered_set 无序集合
// unordered_set 插入元素是无序的；set保证插入元素是有序的；
// 但都是属于集合，元素之间不能相等
// 正好符合题目要求
//

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> gen_codes;

    for(auto word : words) {
        string code = "";
        for(auto ch : word)// auto 循环，简单许多 C++ 11
            code += morse_code[ch - 'a'];//得到对应字母在密码表里的代码
        gen_codes.insert(code);
    }

    return gen_codes.size();//集合元素之间不能相等
}
