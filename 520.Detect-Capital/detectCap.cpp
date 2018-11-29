/**
* 设置一个变量对大写字母进行统计;然后根据统计结果,判断输出内容:
1. == word.size() : 都是大写字母;
2. == 0: 都是小写字母
3. ==1 and isfirstCap: 第一个是大写字母,其他都是小写字母

其他情况,都返回false
*/
class Solution {
public:
    bool detectCapitalUse(string word) {
        //设置一个变量:统计大写字母数目
        if(word.size() == 0)
            return true;
        bool isfirstCap = isCap(word[0]);
        int cntCaps = isfirstCap ? 1 : 0;
        for(int i=1;i<word.size(); i++){
            cntCaps += isCap(word[i]) ? 1 : 0;
        }
        return cntCaps == word.size() || cntCaps == 0 || (cntCaps==1 && isfirstCap);
    }
private:
    bool isCap(char c){
        return c>='A' && c<='Z';
    }
};
